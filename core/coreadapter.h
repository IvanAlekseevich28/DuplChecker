#ifndef COREADAPTER_H
#define COREADAPTER_H


#include "../ICore.h"
#include "duplchecker.h"
#include <QList>


namespace CORE
{
class CoreAdapter : public CONTROLLER::ICore
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

#endif // COREADAPTER_H
