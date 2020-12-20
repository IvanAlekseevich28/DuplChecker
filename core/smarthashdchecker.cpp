#include "smarthashdchecker.h"


using namespace CORE;


SmartHashDChecker::SmartHashDChecker() : m_hashGen()
{

}


QList<FilesPair> SmartHashDChecker::getDuplicationFilesPaths(   QList<QFile>& files1,
                                                                QList<QFile>& files2)
{
    genHash(files1);
    genRawFilesList(files2);
}


void SmartHashDChecker::genHash(QList<QFile>& files)
{
    m_filesHashes.clear();

    for (auto& f : files)
    {
        m_filesHashes.insert(
                    m_hashGen.getHash(f), f);
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
            answLst.push_back(QFilePair(otherFile, f));
        }
    }
}
