#pragma once

#include "core/filespair.h"
#include <QList>

namespace Dupl
{
class IPipeUI
{
public:
    virtual bool showResults(const QList<FilesPair>& pairList)=0;

    virtual ~IPipeUI(){}

protected:
    IPipeUI(){}
};
}
