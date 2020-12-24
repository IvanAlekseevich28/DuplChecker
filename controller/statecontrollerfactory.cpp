#include "statecontrollerfactory.h"

#include "filestatecontroller.h"


using namespace dupl;

StateControllerFactory::StateControllerFactory()
{

}

std::shared_ptr<IStateController> StateControllerFactory::getStateController(eStateController eType)
{
    switch (eType)
    {
    case SimpleFile: return std::shared_ptr<IStateController>(new FileStateController); break;
    }

    return std::shared_ptr<IStateController>();
}
