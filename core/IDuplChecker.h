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
    virtual QList<FilesPair> getDuplicationFilesPaths(QList<QFile>& files1,
                                                      QList<QFile>& files2)=0;

    virtual ~IDuplChecker();

protected:
    IDuplChecker();

};


struct FilesPair
{
    FilesPair(const QString& path1, const QString& path2) :
        pathFile1(path1), pathFile2(path2) {}

    QString pathFile1;
    QString pathFile2;
};
}
#endif // IDUPLCHECKER_H
