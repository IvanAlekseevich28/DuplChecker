#pragma once

#include "../../controller/ipipeui.h"
<<<<<<< HEAD

=======
>>>>>>> 301e9eb3d473f2993fca763422e4693cb196ffe4

namespace dupl
{
class SimpleOutput : public IPipeUI
{
public:
    SimpleOutput();

    bool showResults(const QList<FilesPair>& pairLst)override;

};
}
