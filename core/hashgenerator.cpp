#include "hashgenerator.h"

#include "md5hashgenerator.h"


using namespace CORE;


HashGenerator::HashGenerator()
{
    setAlg();
}


QString HashGenerator::getHash(const QFile& file)const
{
    if (!m_alg) return QString("");

    return m_alg->getHash(file);
}
