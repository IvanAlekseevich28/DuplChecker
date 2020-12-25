#pragma once

#include <QFile>
#include <QList>
#include <QString>
#include "filespair.h"

namespace Dupl
{
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
