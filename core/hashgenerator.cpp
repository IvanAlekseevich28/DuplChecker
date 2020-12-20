#include "hashgenerator.h"

#include "md5hashgenerator.h"


using namespace CORE;


HashGenerator::HashGenerator()
{
    setAlg();
}

HashGenerator::~HashGenerator()
{
    m_alg.release();
}

QString HashGenerator::getHash(QFile& file)const
{
    if (!m_alg) return QString("");

    return m_alg->getHash(file);
}


void HashGenerator::setAlg(eAlg alg)
{
    switch (alg)
    {
        case HashGenerator::md5: m_alg.reset(new md5HashGenerator); break;
    }
}
