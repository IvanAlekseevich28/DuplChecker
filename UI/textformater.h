#pragma once

#include <QStringList>
#include "../core/filespair.h"

namespace Dupl
{
class TextFormater
{
public:
    TextFormater();

    enum eForm
    {
        None            = 0x1,
        ThroughEquals   = 0x2,
//        TwoColumn       = 0x4,
        NoFullPath      = 0x8,
        Pretty          = ThroughEquals | NoFullPath
    };
    QStringList formatPathsList(const QList<FilesPair>& pairList, const eForm f )const;

private:
    QString formatPaths(const FilesPair& pair, const eForm f)const;
    void cutPath(QString& path1, QString& path2, bool fDelOneMore = true) const;
    QString makePath(const QStringList& list)const;
};
}

