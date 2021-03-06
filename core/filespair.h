#pragma once

#include <QList>
#include <QString>

namespace Dupl
{
struct FilesPair
{
    FilesPair(const QString& path1, const QString& path2) :
        pathFile1(path1), pathFile2(path2) {}

    QString pathFile1;
    QString pathFile2;
};
}
