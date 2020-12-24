#pragma once

#include "basestatecontroller.h"


namespace dupl
{
class FileStateController : public BaseStateController
{
public:
    FileStateController(){};
    ~FileStateController()override{}

    bool save() override;
    bool load() override;

};
}
