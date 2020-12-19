#ifndef MD5HASHGENERATOR_H
#define MD5HASHGENERATOR_H


#include "hashgenerator.h"


namespace CORE
{
class md5HashGenerator : public HashGenerator
{
public:
    QString getHash(const QFile& file)const override;
    md5HashGenerator();
    ~md5HashGenerator();
};
}
#endif // MD5HASHGENERATOR_H
