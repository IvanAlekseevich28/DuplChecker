#pragma once

#include "../../controller/ipipeui.h"
#include <memory>


namespace CLI
{
class TextOutput
{
public:
    TextOutput();

    bool print(const QList<CORE::FilesPair>& pairLst);

    void setTypeOutput();
private:
    std::unique_ptr<CONTROLLER::IPipeUI> m_output;
};
}
