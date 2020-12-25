#pragma once

#include "../../controller/ipipeui.h"
#include <memory>

namespace Dupl
{
class TextOutput
{
public:
    TextOutput();
    ~TextOutput();

    bool print(const QList<FilesPair>& pairList);

    void setTypeOutput();
private:
    std::unique_ptr<IPipeUI> m_output;
};
}
