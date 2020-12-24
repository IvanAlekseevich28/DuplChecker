#include "textoutput.h"

#include "simpleoutput.h"


using namespace dupl;


TextOutput::TextOutput()
{
    setTypeOutput();
}

bool TextOutput::print(const QList<FilesPair>& pairLst)
{
    if (!m_output) return false;

    return m_output->showResults(pairLst);
}

void TextOutput::setTypeOutput()
{
    m_output.reset(new SimpleOutput());
}
