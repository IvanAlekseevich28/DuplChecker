#ifndef IDUPLCHECKER_H
#define IDUPLCHECKER_H

#include <QFile>
#include <QList>
#include <QString>
#include <memory>


namespace CORE
{
struct FilesPair;
class DuplChecker
{
public:
    DuplChecker();
    virtual ~DuplChecker();

    virtual QList<FilesPair> getDuplicationFilesPaths(QList<QFile>& files1,
                                                      QList<QFile>& files2);

    enum eAlg
    {
        SmartHash
    };
    void setDuplicateChackerAlg(eAlg = SmartHash);

private:
    std::unique_ptr<DuplChecker> m_duplChecker;
};


struct FilesPair
{
    QString pathFile1;
    QString pathFile2;
};
}
#endif // IDUPLCHECKER_H
