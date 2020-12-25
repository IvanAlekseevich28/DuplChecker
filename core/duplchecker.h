#pragma once

#include "iduplchecker.h"
#include <memory>

namespace Dupl
{
struct FilesPair;
class DuplChecker
{
public:
    DuplChecker();
    ~DuplChecker(){}

    QList<FilesPair> getDuplicationFilesPaths(QList<QFile*>& files1,
                                              QList<QFile*>& files2) const;
    enum eAlg
    {
        SmartHash
    };
    void setDuplicateChackerAlg(eAlg = SmartHash);

private:
    std::unique_ptr<IDuplChecker> m_duplChecker;
};
}
