#include <kao2engine/eGroupCtrl.h>
#include <kao2ar/Archive.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eGroupCtrl interface
    // <kao2.0042CB53> (constructor)
    // <kao2.0042CC00> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_GROUPCTRL_TYPEINFO
    (
        E_GROUPCTRL_ID,
        "eGroupCtrl",
        &E_GADGET_TYPEINFO,
        []() -> eObject*
        {
            return new eGroupCtrl;
        }
    );

    TypeInfo* eGroupCtrl::getType()
    {
        return &E_GROUPCTRL_TYPEINFO;
    }

    eGroupCtrl::eGroupCtrl()
    : Gadget()
    {
        /* [0x10] */ unknown_10 = nullptr;
        /* [0x14] */ unknown_14 = 0x00;
    }

    eGroupCtrl::~eGroupCtrl()
    {
        if (nullptr != unknown_10)
        {
            unknown_10->decRef();
        }
    }


    ////////////////////////////////////////////////////////////////
    // eGroupCtrl serialization
    // <kao2.0042D2A0>
    ////////////////////////////////////////////////////////////////
    void eGroupCtrl::serialize(Archive &ar)
    {
        Gadget::serialize(ar);

        /* [0x14] unknown value */

        ar.readOrWrite(&unknown_14, 0x01);

        /* [0x10] unknown object */

        ArFunctions::serialize_eRefCounter(ar, (eRefCounter**)&unknown_10, nullptr);
    }


    ////////////////////////////////////////////////////////////////
    // eGroupCtrl: get default name (scripting shenanigans)
    ////////////////////////////////////////////////////////////////
    eString eGroupCtrl::getDefaultGadgetName()
    {
        return "group";
    }

}
