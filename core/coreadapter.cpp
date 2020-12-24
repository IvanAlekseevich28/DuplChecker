#include "coreadapter.h"

#include <QDirIterator>
#include "duplchecker.h"


using namespace dupl;


CoreAdapter::CoreAdapter() : m_adaptee(new DuplChecker())
{

}

CoreAdapter::~CoreAdapter()
{

}

QList<FilesPair> CoreAdapter::compareTwoDirs(const QString& dir1, const QString& dir2)
{

    QList<QFile*> files1 = getPtrFilesLst(dir1);
    QList<QFile*> files2 = getPtrFilesLst(dir2);

    auto answer = m_adaptee->getDuplicationFilesPaths(files1, files2);

    clearFiles(files1);
    clearFiles(files2);

    return answer;
}

QList<QFile*> CoreAdapter::getPtrFilesLst(const QString& dir)
{
    QList<QFile*> filesLst;
    QDirIterator ItR(dir,  QDir::Files, QDirIterator::Subdirectories);
    while (ItR.hasNext()) {
        auto p (new QFile(ItR.next()));
        filesLst.push_back(p);
    }

    return filesLst;
}

void CoreAdapter::clearFiles(QList<QFile*> &fLst)
{
    for (auto p : fLst)
    {
        if (p)
        {
            delete p;
            p = nullptr;
        }
    }
}
