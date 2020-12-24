#pragma once

#include "core/filespair.h"
#include <QList>


namespace dupl
{
class IPipeUI
{
public:
    virtual bool showResults(const QList<FilesPair>& pairLst)=0;

    virtual ~IPipeUI(){}

protected:
    IPipeUI(){}
};
}
