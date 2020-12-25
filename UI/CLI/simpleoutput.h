#pragma once

#include "../../controller/ipipeui.h"

namespace Dupl
{
class SimpleOutput : public IPipeUI
{
public:
    SimpleOutput();
    ~SimpleOutput() override;

    bool showResults(const QList<FilesPair>& pairList) override;

};
}
