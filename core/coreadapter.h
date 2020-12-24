#pragma once

#include "../controller/icore.h"
#include <QList>
#include <QFile>
#include <memory>


namespace dupl
{
class DuplChecker;
class CoreAdapter : public ICore
{
public:
    CoreAdapter();
    ~CoreAdapter();

    QList<FilesPair> compareTwoDirs(const QString& dir1, const QString& dir2)override;

private:
    QList<QFile*> getPtrFilesLst(const QString& dir);
    void clearFiles(QList<QFile*> &fLst);

private:
    std::unique_ptr<DuplChecker> m_adaptee;
};
}
