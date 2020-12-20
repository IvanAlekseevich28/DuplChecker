#ifndef MD5HASHGENERATOR_H
#define MD5HASHGENERATOR_H


#include "IHashGenerator.h"
#include <QByteArray>


namespace CORE
{
class md5HashGenerator : public IHashGenerator
{
public:
    QString getHash(QFile& file)const override;
    md5HashGenerator();
    ~md5HashGenerator()override;

};
}
#endif // MD5HASHGENERATOR_H
