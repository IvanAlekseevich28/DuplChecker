#ifndef SIMPLEOUTPUT_H
#define SIMPLEOUTPUT_H


#include "../../IPipeUI.h"


namespace CLI
{
class SimpleOutput : public CONTROLLER::IPipeUI
{
public:
    SimpleOutput();

    bool showResults(const QList<CORE::FilesPair>& pairLst)override;

};
}
#endif // SIMPLEOUTPUT_H
