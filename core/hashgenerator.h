#ifndef HASHGENERATOR_H
#define HASHGENERATOR_H

#include <memory>
#include "IHashGenerator.h"

namespace CORE
{
class HashGenerator
{
public:
    HashGenerator();
    ~HashGenerator();

    QString getHash(QFile& file)const;

    enum eAlg
    {
        md5
    };
    void setAlg(eAlg alg = md5);


private:
    std::unique_ptr<IHashGenerator> m_alg;
};
}
#endif // HASHGENERATOR_H
