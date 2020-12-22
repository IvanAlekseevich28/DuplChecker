#include "simpleoutput.h"

#include "../textformater.h"
#include <iostream>


using namespace CLI;
using namespace std;


SimpleOutput::SimpleOutput()
{

}

bool SimpleOutput::showResults(const QList<CORE::FilesPair>& pairLst)
{
    TextFormater tf;

    //Todo
    auto QStrLst = tf.formatPathsList(pairLst, TextFormater::NoFullPath /*| TextFormater::ThroughEquals*/);
    bool isNotErrors = true;
    for (const auto& p : QStrLst)
    {
        cout << p.toStdString() << "\n";
    }

    return isNotErrors;
}


