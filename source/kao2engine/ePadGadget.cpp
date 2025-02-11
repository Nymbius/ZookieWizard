#include <kao2engine/ePadGadget.h>
#include <kao2ar/Archive.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // ePadGadget interface
    // <kao2.004C8390> (constructor)
    // <kao2.004C8460> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_PADGADGET_TYPEINFO
    (
        E_PADGADGET_ID,
        "ePadGadget",
        &E_GADGET_TYPEINFO,
        []() -> eObject*
        {
            return new ePadGadget;
        }
    );

    TypeInfo* ePadGadget::getType()
    {
        return &E_PADGADGET_TYPEINFO;
    }

    ePadGadget::ePadGadget()
    : Gadget()
    {}

    ePadGadget::~ePadGadget() {}


    ////////////////////////////////////////////////////////////////
    // ePadGadget: get default name (scripting shenanigans)
    ////////////////////////////////////////////////////////////////
    eString ePadGadget::getDefaultGadgetName()
    {
        return "pad";
    }

}
