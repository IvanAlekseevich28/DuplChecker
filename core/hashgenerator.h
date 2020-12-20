#ifndef HASHGENERATOR_H
#define HASHGENERATOR_H

#include <memory>
#include <QString>
#include <QFile>

namespace CORE
{
class HashGenerator
{
public:
    HashGenerator();
    virtual ~HashGenerator();

    virtual QString getHash(QFile& file)const;

public:
    enum eAlg
    {
        md5
    };
    void setAlg(eAlg alg = md5);


private:
    std::unique_ptr<HashGenerator> m_alg;
};
}
#endif // HASHGENERATOR_H
