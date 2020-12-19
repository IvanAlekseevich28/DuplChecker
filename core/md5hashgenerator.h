#ifndef MD5HASHGENERATOR_H
#define MD5HASHGENERATOR_H


#include "hashgenerator.h"
#include <QByteArray>


namespace CORE
{
class md5HashGenerator : public HashGenerator
{
public:
    QString getHash(QFile& file)const override;
    md5HashGenerator();
    ~md5HashGenerator();

private:

};
}
#endif // MD5HASHGENERATOR_H
