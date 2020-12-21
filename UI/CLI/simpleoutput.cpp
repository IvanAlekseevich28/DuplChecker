#include "simpleoutput.h"
#include <iostream>


using namespace CLI;
using namespace std;


SimpleOutput::SimpleOutput()
{

}

bool SimpleOutput::showResults(const QList<CORE::FilesPair>& pairLst)
{
    bool isNotErrors = true;
    for (const auto& p : pairLst)
    {
        if (!printFilesPair(p))
        {
            isNotErrors = false;
            break;
        }
    }

    return isNotErrors;
}

bool SimpleOutput::printFilesPair(const CORE::FilesPair& paths)
{
    cout << removeLongPath(paths.pathFile1).toStdString()
         << " == "
         << removeLongPath(paths.pathFile2).toStdString()
         << "\n";

    return true;
}

QString SimpleOutput::removeLongPath(const QString& str)
{
    return str;
}
