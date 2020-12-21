#ifndef IPIPEUI_H
#define IPIPEUI_H


#include "core/filespair.h"
#include <QList>


namespace CONTROLLER
{
class IPipeUI
{
public:
    virtual bool showResults(const QList<CORE::FilesPair>& pairLst)=0;

    virtual ~IPipeUI(){}

protected:
    IPipeUI(){}
};
}
#endif // IPIPEUI_H
