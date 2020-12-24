#pragma once

#include "../../controller/ipipeui.h"


namespace CLI
{
class SimpleOutput : public CONTROLLER::IPipeUI
{
public:
    SimpleOutput();

    bool showResults(const QList<CORE::FilesPair>& pairLst)override;

};
}
