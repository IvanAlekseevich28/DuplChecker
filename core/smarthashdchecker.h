#ifndef SMARTHASHDCHECKER_H
#define SMARTHASHDCHECKER_H


#include "duplchecker.h"
#include <QHash>


namespace CORE
{
class SmartHashDChecker : public DuplChecker
{
public:
    SmartHashDChecker();
    ~SmartHashDChecker() override;

    QList<FilesPair> getDuplicationFilesPaths(const QList<QFile>& files1,
                                              const QList<QFile>& files2)const override;

private:
    void genHash(const QList<QFile>& files);
    QList<QFile>& genRawFilesList()const;
    QList<QFile>& binaryChecker()const;
    bool binaryCompare(QFile)const;


private:
    QHash<QString, QFile&> m_filesHashes;

};
}
#endif // SMARTHASHDCHECKER_H
