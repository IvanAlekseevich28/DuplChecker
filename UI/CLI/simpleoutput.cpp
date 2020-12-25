#include "simpleoutput.h"

#include "../textformater.h"
#include <iostream>

using namespace Dupl;
using namespace std;

SimpleOutput::SimpleOutput()
{

}

SimpleOutput::~SimpleOutput()
{

}

bool SimpleOutput::showResults(const QList<FilesPair>& pairList)
{
    TextFormater tf;

    auto QStrList = tf.formatPathsList(pairList, TextFormater::Pretty);
    bool isNotErrors = true;
    for (const auto& files : QStrList)
    {
        cout << files.toStdString() << "\n";
    }

    return isNotErrors;
}


