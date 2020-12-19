#ifndef HASHGENERATOR_H
#define HASHGENERATOR_H

#include <boost/optional.hpp>
#include <QString>
#include <QFile>

namespace CORE
{
class HashGenerator
{
public:
    HashGenerator();
    virtual ~HashGenerator();

    virtual QString getHash(const QFile& file)const;

public:
    enum eAlg
    {
        md5
    };
    void setAlg(eAlg alg = md5);


private:
    boost::optional<HashGenerator> m_alg;
};
}
#endif // HASHGENERATOR_H
