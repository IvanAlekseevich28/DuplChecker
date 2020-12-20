#include "smarthashdchecker.h"


using namespace CORE;


SmartHashDChecker::SmartHashDChecker() : m_hashGen()
{

}


QList<FilesPair> SmartHashDChecker::getDuplicationFilesPaths(   QList<QFile>& files1,
                                                                QList<QFile>& files2)
{
    genHash(files1);
    auto rawLst = genRawFilesList(files2);

    return binaryChecker(rawLst);
}


void SmartHashDChecker::genHash(QList<QFile>& files)
{
    m_filesHashes.clear();

    for (auto& f : files)
    {
        m_filesHashes.insert(
                    m_hashGen.getHash(f), &f);
    }
}


QList<SmartHashDChecker::QFilePair> SmartHashDChecker::genRawFilesList(QList<QFile>& files)const
{
    QList<SmartHashDChecker::QFilePair> answLst;

    for (auto& f : files)
    {
        auto otherFile = m_filesHashes.find(m_hashGen.getHash(f));
        if (otherFile != m_filesHashes.end())
        {
            answLst.push_back(QFilePair(*(otherFile.value()), f));
        }
    }

    return answLst;
}


QList<FilesPair> SmartHashDChecker::binaryChecker(QList<QFilePair>& rawLst)const
{
    QList<FilesPair> answLst;
    for (const auto& pair : rawLst)
    {
        if (binaryCompare(pair))
            answLst.push_back(FilesPair(pair.file1->fileName(), pair.file2->fileName()));
    }

    return answLst;
}


bool SmartHashDChecker::binaryCompare(const QFilePair& pair)const
{
    if (pair.file1->fileName() == pair.file2->fileName()) return false;

    return true;
}
