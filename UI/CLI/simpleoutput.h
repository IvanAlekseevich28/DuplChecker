#pragma once

#include "../../controller/ipipeui.h"

namespace dupl
{
class SimpleOutput : public IPipeUI
{
public:
    SimpleOutput();

    bool showResults(const QList<FilesPair>& pairLst)override;

};
}
