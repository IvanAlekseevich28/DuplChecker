#pragma once

#include "../../controller/ipipeui.h"
#include <memory>


namespace dupl
{
class TextOutput
{
public:
    TextOutput();

    bool print(const QList<FilesPair>& pairLst);

    void setTypeOutput();
private:
    std::unique_ptr<IPipeUI> m_output;
};
}
