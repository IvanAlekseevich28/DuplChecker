#include "duplchecker.h"


namespace CORE
{
DuplChecker::DuplChecker()
{
    setDuplicateChackerAlg();
}

QList<FilesPair> DuplChecker::getDuplicationFilesPaths(const QList<QFile>& files1,
                                                      const QList<QFile>& files2)const
{
    if (!m_duplChecker) return QList<FilesPair>();

    return m_duplChecker->getDuplicationFilesPaths(files1, files2);
}
}
