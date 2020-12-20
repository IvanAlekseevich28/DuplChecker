#include "duplchecker.h"

#include "smarthashdchecker.h"


namespace CORE
{
DuplChecker::DuplChecker()
{
    setDuplicateChackerAlg();
}

QList<FilesPair> DuplChecker::getDuplicationFilesPaths(QList<QFile>& files1,
                                                      QList<QFile>& files2) const
{
    if (!m_duplChecker) return QList<FilesPair>();

    return m_duplChecker->getDuplicationFilesPaths(files1, files2);
}


void DuplChecker::setDuplicateChackerAlg(eAlg ealg)
{
    switch (ealg)
    {
    case DuplChecker::SmartHash: m_duplChecker.reset(new SmartHashDChecker); break;
    }
}
}
