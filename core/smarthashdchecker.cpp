#include "smarthashdchecker.h"

using namespace CORE;


SmartHashDChecker::SmartHashDChecker() : m_hash(QCryptographicHash::Algorithm::Md5)
{

}

SmartHashDChecker::~SmartHashDChecker()
{

}


QList<FilesPair> SmartHashDChecker::getDuplicationFilesPaths(QList<QFile *> &files1,
                                                                QList<QFile *> &files2)
{
    genHash(files1);
    auto rawLst = genRawFilesList(files2);

    return binaryChecker(rawLst);
}


void SmartHashDChecker::genHash(QList<QFile*>& files)
{
    m_filesHashes.clear();

    QCryptographicHash hash(QCryptographicHash::Algorithm::Md5);
    for (auto f : files)
    {
        hash.reset();
        hash.addData(f);
        m_filesHashes.insert(
                    genHash(f), f);
    }
}

QString SmartHashDChecker::genHash(QFile *file)
{
    file->open(QIODevice::ReadOnly);

    m_hash.reset();
    m_hash.addData(file);

    file->close();

    return QString(m_hash.result().toHex());
}


QList<SmartHashDChecker::QFilePair> SmartHashDChecker::genRawFilesList(QList<QFile*>& files)
{
    QList<SmartHashDChecker::QFilePair> answLst;

    for (auto pFile : files)
    {
        auto otherFile = m_filesHashes.find(genHash(pFile));
        if (otherFile != m_filesHashes.end())
            answLst.push_back(QFilePair(*(otherFile.value()), *pFile));
    }

    return answLst;
}


QList<FilesPair> SmartHashDChecker::binaryChecker(QList<QFilePair>& rawLst)const
{
    QList<FilesPair> answLst;
//    auto iter = rawLst.begin(); iter != rawLst.end(); iter++
    for (auto& pair : rawLst)
    {
        if (binaryCompare(pair))
            answLst.push_back(FilesPair(pair.file1->fileName(), pair.file2->fileName()));
    }

    return answLst;
}


bool SmartHashDChecker::binaryCompare(const QFilePair& pair)const
{
    if (pair.file1->fileName() == pair.file2->fileName()) return false;

    QFile& f1 (*(pair.file1));
    QFile& f2 (*(pair.file2));

    auto fileSize = f1.size();
    if (fileSize != f2.size()) return false;

    if (!f1.open(QFile::ReadOnly)) return false;
    if (!f2.open(QFile::ReadOnly)) return false;

    // U can read it not all for one time. But why?
    if (f1.readAll() != f2.readAll()) return false;

    f1.close();
    f2.close();

    return true;
}
