#include "simpleoutput.h"

#include "../textformater.h"
#include <iostream>


using namespace dupl;
using namespace std;


SimpleOutput::SimpleOutput()
{

}

bool SimpleOutput::showResults(const QList<FilesPair>& pairLst)
{
    TextFormater tf;

    auto QStrLst = tf.formatPathsList(pairLst, TextFormater::Pretty);
    bool isNotErrors = true;
    for (const auto& p : QStrLst)
    {
        cout << p.toStdString() << "\n";
    }

    return isNotErrors;
}


