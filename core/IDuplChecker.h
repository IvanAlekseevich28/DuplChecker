#ifndef IDUPLCHECKER_H
#define IDUPLCHECKER_H


#include <QFile>
#include <QList>
#include <QString>
#include "filespair.h"


namespace CORE
{
struct FilesPair;
class IDuplChecker
{
public:
    virtual QList<FilesPair> getDuplicationFilesPaths(QList<QFile*>& files1,
                                                      QList<QFile*>& files2)=0;

    virtual ~IDuplChecker(){}

protected:
    IDuplChecker(){}

};
}
#endif // IDUPLCHECKER_H
