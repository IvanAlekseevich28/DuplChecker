#ifndef IDUPLCHECKER_H
#define IDUPLCHECKER_H

#include <QFile>
#include <QList>
#include <QString>
#include <boost/optional.hpp>


namespace CORE
{
struct FilesPair;
class DuplChecker
{
public:
    DuplChecker();
    virtual ~DuplChecker();

    virtual QList<FilesPair> getDuplicationFilesPaths(const QList<QFile>& files1,
                                                      const QList<QFile>& files2)const;

    enum eAlg
    {
        SmartHash
    };
    void setDuplicateChackerAlg(eAlg = SmartHash);

private:
    boost::optional<DuplChecker> m_duplChecker;
};


struct FilesPair
{
    QString pathFile1;
    QString pathFile2;
};
}
#endif // IDUPLCHECKER_H
