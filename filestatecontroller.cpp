#include "filestatecontroller.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>


using namespace CONTROLLER;


class JSON_GUIState
{
public:
    static QJsonObject toJson(const GUIState& st)
    {
        QJsonObject obj;

        QJsonObject val;
        val["path1"] = st.path1;
        val["path2"] = st.path2;
        obj["GUIState"] = val;

        return obj;
    }
    static GUIState    fromJson(const QJsonObject &obj)
    {
        GUIState st;
        if (obj.contains("GUIState") && obj["GUIState"].isObject())
        {
            auto jsonSt = obj["GUIState"].toObject();
            if (jsonSt.contains("path1") && jsonSt["path1"].isString())
                st.path1 = jsonSt["path1"].toString();
            if (jsonSt.contains("path2") && jsonSt["path2"].isString())
                st.path2 = jsonSt["path2"].toString();

        }
        return st;
    }
};



bool FileStateController::save()
{
    QFile f(getPath());
    if (!f.open(QFile::WriteOnly)) return false;

    QJsonDocument doc(JSON_GUIState::toJson(getGUIState()));
    f.write(doc.toJson());

    f.close();
    return true;
}
bool FileStateController::load()
{
    QFile f(getPath());
    if (!f.open(QFile::ReadOnly)) return false;

    QJsonDocument loadDoc(QJsonDocument::fromJson(f.readAll()));
    setGUIState(JSON_GUIState::fromJson(loadDoc.object()));


    f.close();
    return true;
}
