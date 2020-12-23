#include "filestatecontroller.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>


using namespace CONTROLLER;


class JSON_GUIState
{
public:
    QJsonObject toJson(const GUIState& st)
    {
        QJsonObject obj;

        QJsonObject val;
        val["path1"] = st.path1;
        val["path2"] = st.path2;
        obj["GUIState"] = val;

        return obj;
    }
    GUIState    fromJson(const QJsonObject &obj)
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
private:
    static QString ThisObjName;
};


FileStateController::FileStateController()
{

}

GUIState FileStateController::getGUIState()const
{

}
void FileStateController::setGUIState(const GUIState& state)
{

}

bool FileStateController::save()
{

}
bool FileStateController::load()
{

}
