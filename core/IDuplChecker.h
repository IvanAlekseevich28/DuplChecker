#ifndef IDUPLCHECKER_H
#define IDUPLCHECKER_H

#include <QFile>
#include <QList>
#include <QString>


namespace CORE
{
struct FilesPair;
class IDuplChecker
{
public:
    virtual void setFiles(const QList<QFile>& files)=0;
    virtual QList<FilesPair> getDuplicationFilesPaths()const =0;
protected:
    IDuplChecker();
    virtual ~IDuplChecker()=0;
};


struct FilesPair
{
    QString pathFile1;
    QString pathFile2;
};
}
#endif // IDUPLCHECKER_H
