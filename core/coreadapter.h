#ifndef COREADAPTER_H
#define COREADAPTER_H


#include "../ICore.h"
#include "hashgenerator.h"


namespace CORE
{
class CoreAdapter : public CONTROLLER::ICore
{
public:
    CoreAdapter();

    QList<FilesPair> compareTwoDirs(const QString& dir1, const QString& dir2)override;

private:
    std::unique_ptr<HashGenerator> m_adaptee;
};
}

#endif // COREADAPTER_H
