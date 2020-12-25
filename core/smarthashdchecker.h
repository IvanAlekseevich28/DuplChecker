#pragma once

#include "iduplchecker.h"
#include <QHash>
#include <QCryptographicHash>

namespace Dupl
{
class SmartHashDChecker : public IDuplChecker
{
public:
    SmartHashDChecker();
    ~SmartHashDChecker() override;

    QList<FilesPair> getDuplicationFilesPaths(QList<QFile*>& files1,
                                              QList<QFile*>& files2) override;

private:
    struct QFilePair
    {
        QFilePair(QFile& file1, QFile& file2)
            : file1(&file1), file2(&file2) {}

        QFile* file1;
        QFile* file2;
    };
private:
    void genHash(QList<QFile*> &files);
    QString genHash(QFile* file);
    QList<QFilePair> genRawFilesList(QList<QFile*>& files);
    QList<FilesPair> binaryChecker(QList<QFilePair>& rawList)const;
    bool binaryCompare(const QFilePair& pair)const;


private:
    QHash<QString, QFile*> m_filesHashes;
    QCryptographicHash m_hash;

};
}
