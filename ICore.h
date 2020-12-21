#ifndef ICORE_H
#define ICORE_H


#include "core/IDuplChecker.h"


namespace CONTROLLER
{
class ICore
{
public:
    virtual QList<CORE::FilesPair> compareTwoDirs(const QString& dir1, const QString& dir2)=0;

    virtual ~ICore(){}

protected:
    ICore(){}
};
}
#endif // ICORE_H
