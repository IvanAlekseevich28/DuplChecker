#ifndef FILESPAIR_H
#define FILESPAIR_H


#include <QList>
#include <QString>


namespace CORE
{
struct FilesPair
{
    FilesPair(const QString& path1, const QString& path2) :
        pathFile1(path1), pathFile2(path2) {}

    QString pathFile1;
    QString pathFile2;
};
}
#endif // FILESPAIR_H
