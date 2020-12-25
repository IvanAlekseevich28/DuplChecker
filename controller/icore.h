#pragma once

#include "core/filespair.h"

namespace Dupl
{
class ICore
{
public:
    virtual QList<FilesPair> compareTwoDirs(const QString& dir1, const QString& dir2)=0;

    virtual ~ICore(){}

protected:
    ICore(){}
};
}
