#ifndef SMARTHASHDCHECKER_H
#define SMARTHASHDCHECKER_H


#include "IDuplChecker.h"


namespace CORE
{
class SmartHashDChecker : public IDuplChecker
{
public:
    SmartHashDChecker();
    ~SmartHashDChecker() override;
    void setFiles(const QList<QFile>& files) override;
    QList<FilesPair> getDuplicationFilesPaths()const override;

private:

};
}
#endif // SMARTHASHDCHECKER_H
