#include "coreadapter.h"

#include <QDirIterator>
#include "duplchecker.h"

using namespace Dupl;

CoreAdapter::CoreAdapter() : m_adaptee(new DuplChecker())
{

}

CoreAdapter::~CoreAdapter()
{

}

QList<FilesPair> CoreAdapter::compareTwoDirs(const QString& dir1, const QString& dir2)
{

    QList<QFile*> files1 = getFilesList(dir1);
    QList<QFile*> files2 = getFilesList(dir2);

    auto answer = m_adaptee->getDuplicationFilesPaths(files1, files2);

    clearFiles(files1);
    clearFiles(files2);

    return answer;
}

QList<QFile*> CoreAdapter::getFilesList(const QString& dir)
{
    QList<QFile*> filesList;
    QDirIterator ItR(dir,  QDir::Files, QDirIterator::Subdirectories);
    while (ItR.hasNext()) {
        auto p (new QFile(ItR.next()));
        filesList.push_back(p);
    }

    return filesList;
}

void CoreAdapter::clearFiles(QList<QFile*> &fList)
{
    for (auto p : fList)
    {
        if (p)
        {
            delete p;
            p = nullptr;
        }
    }
}
