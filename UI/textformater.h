#ifndef TEXTFORMATER_H
#define TEXTFORMATER_H


#include <QStringList>
#include "../core/filespair.h"


class TextFormater
{
public:
    TextFormater();

    enum eForm
    {
        None            = 0x1,
        ThroughEquals   = 0x2,
//        TwoColumn       = 0x4,
        NoFullPath      = 0x8
    };
    QStringList formatPathsList(const QList<CORE::FilesPair>& pairLst, const eForm f)const;

private:
    QString formatPaths(const CORE::FilesPair& pair, const eForm f)const;
    void cutPath(QString &path1, QString &path2, bool fDelOneMore = true)const;
    QString makePath(const QStringList& lst)const;
};

#endif // TEXTFORMATER_H
