#pragma once

#include "../controller/icore.h"
#include <QList>
#include <QFile>
#include <memory>

namespace Dupl
{
class DuplChecker;
class CoreAdapter : public ICore
{
public:
    CoreAdapter();
    ~CoreAdapter() override;

    QList<FilesPair> compareTwoDirs(const QString& dir1, const QString& dir2) override;

private:
    QList<QFile*> getFilesList(const QString& dir);
    void clearFiles(QList<QFile*> &fList);

private:
    std::unique_ptr<DuplChecker> m_adaptee;
};
}
