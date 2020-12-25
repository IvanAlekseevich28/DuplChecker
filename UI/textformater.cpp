#include "textformater.h"

#ifdef __linux__
    #define SPLITER "/"
#elif _WIN32
    #define SPLITER "\\"
#else
    #define SPLITER "/"
#endif

using namespace Dupl;

TextFormater::TextFormater()
{

}


QStringList TextFormater::formatPathsList(const QList<FilesPair>& pairList, const eForm f)const
{
    QStringList answerList;
    for (const auto& p : pairList)
    {
        answerList.push_back(formatPaths(p, f));
    }

    return answerList;
}


QString TextFormater::formatPaths(const FilesPair& pair, const eForm f)const
{
    QString answer;
    QString p1(pair.pathFile1), p2(pair.pathFile2);

    if ((f & None) == None)
    {
        return QString(pair.pathFile1 + pair.pathFile2);
    }

    if ((f & NoFullPath) == NoFullPath)
    {
        cutPath(p1,p2, true);
        answer += p1;
    }
    answer += " ";

    if ((f & ThroughEquals) == ThroughEquals)
    {
        answer += "= ";
    }
    if ((f & NoFullPath) == NoFullPath)
    {
        answer += p2;
    }


    return answer;
}


void TextFormater::cutPath(QString& path1, QString& path2, bool fDelOneMore)const
{
    QStringList files1 = path1.split(SPLITER);
    QStringList files2 = path2.split(SPLITER);

    path1.clear();
    path2.clear();

    for (auto i1(files1.begin()), i2(files2.begin()); i1 != files1.end() && i2 != files2.end(); i1++, i2++)
    {
        if (*i1 == *i2)
        {
            files1.pop_front();
            files2.pop_front();
        } else if (fDelOneMore && files1.size() > 1 && files2.size() > 1)
        {
            fDelOneMore = false;
            files1.pop_front();
            files2.pop_front();
        } else
            break;
    }

    path1 = makePath(files1);
    path2 = makePath(files2);
}


QString TextFormater::makePath(const QStringList& list)const
{
    bool isNotFirst = false;
    QString path;

    for (const auto& part : list)
    {
        if(isNotFirst)
            path += SPLITER;
        else
            isNotFirst = true;

        path += part;
    }

    return path;
}
