#include "textoutput.h"

#include "simpleoutput.h"


using namespace Dupl;


TextOutput::TextOutput()
{
    setTypeOutput();
}

TextOutput::~TextOutput()
{

}

bool TextOutput::print(const QList<FilesPair>& pairList)
{
    if (!m_output) return false;

    return m_output->showResults(pairList);
}

void TextOutput::setTypeOutput()
{
    m_output.reset(new SimpleOutput());
}
