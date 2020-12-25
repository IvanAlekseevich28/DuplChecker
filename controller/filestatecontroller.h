#pragma once

#include "basestatecontroller.h"

namespace Dupl
{
class FileStateController : public BaseStateController
{
public:
    FileStateController(){};
    ~FileStateController() override{}

    bool save() override;
    bool load() override;

};
}
