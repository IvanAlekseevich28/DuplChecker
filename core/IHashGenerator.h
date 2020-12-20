#ifndef IHASHGENERATOR_H
#define IHASHGENERATOR_H


#include <QString>
#include <QFile>


namespace CORE
{
class IHashGenerator
{
public:

    virtual QString getHash(QFile& file)const=0;

    virtual ~IHashGenerator();

protected:
    IHashGenerator();

};
}
#endif // IHASHGENERATOR_H
