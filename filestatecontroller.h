#ifndef FILESTATECONTROLLER_H
#define FILESTATECONTROLLER_H


#include "AbstratStateController.h"
#include <memory>
#include <QFile>


namespace CONTROLLER
{
class FileStateController : public AbstratStateController
{
public:
    FileStateController(){};
    ~FileStateController()override;

    bool save() override;
    bool load() override;

};
}

#endif // FILESTATECONTROLLER_H
