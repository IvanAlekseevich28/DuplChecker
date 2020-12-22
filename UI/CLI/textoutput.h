#ifndef TEXTOUTPUT_H
#define TEXTOUTPUT_H


#include "../../IPipeUI.h"
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
#endif // TEXTOUTPUT_H
