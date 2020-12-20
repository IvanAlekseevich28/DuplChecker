#ifndef DUPLCHECKER_H
#define DUPLCHECKER_H

#include "IDuplChecker.h"
#include <memory>


namespace CORE
{
struct FilesPair;
class DuplChecker
{
public:
    DuplChecker();
    ~DuplChecker(){}

    QList<FilesPair> getDuplicationFilesPaths(QList<QFile*>& files1,
                                              QList<QFile*>& files2)const;

    enum eAlg
    {
        SmartHash
    };
    void setDuplicateChackerAlg(eAlg = SmartHash);

private:
    std::unique_ptr<IDuplChecker> m_duplChecker;
};
}
#endif // DUPLCHECKER_H
