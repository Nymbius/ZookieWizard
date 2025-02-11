#include <kao2engine/eTeleportCtrl.h>
#include <kao2ar/Archive.h>

#include <kao2engine/eRndNavi.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eTeleportCtrl interface
    // <kao2.00431093> (constructor)
    // <kao2.00431160> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_TELEPORTCTRL_TYPEINFO
    (
        E_TELEPORTCTRL_ID,
        "eTeleportCtrl",
        &E_GADGET_TYPEINFO,
        []() -> eObject*
        {
            return new eTeleportCtrl;
        }
    );

    TypeInfo* eTeleportCtrl::getType()
    {
        return &E_TELEPORTCTRL_TYPEINFO;
    }

    eTeleportCtrl::eTeleportCtrl()
    : Gadget()
    {
        /*[0x10]*/ unknown_10 = nullptr;
    }

    eTeleportCtrl::~eTeleportCtrl()
    {
        if (nullptr != unknown_10)
        {
            unknown_10->decRef();
        }
    }


    ////////////////////////////////////////////////////////////////
    // eTeleportCtrl serialization
    // <kao2.00430FD0>
    ////////////////////////////////////////////////////////////////
    void eTeleportCtrl::serialize(Archive &ar)
    {
        /* (NOTE: GADGET FUNCTION IS NOT CALLED) */

        if (ar.isInReadMode())
        {
            ar.replaceStringDuringSerialization(name, getDefaultGadgetName());
        }

        /* [0x10] unknown object */

        ArFunctions::serialize_eRefCounter(ar, (eRefCounter**)&unknown_10, &E_RNDNAVI_TYPEINFO);
    }


    ////////////////////////////////////////////////////////////////
    // eTeleportCtrl: get default name (scripting shenanigans)
    ////////////////////////////////////////////////////////////////
    eString eTeleportCtrl::getDefaultGadgetName()
    {
        return "teleport";
    }

}
