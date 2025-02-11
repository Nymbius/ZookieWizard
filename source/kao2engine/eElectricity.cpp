#include <kao2engine/eElectricity.h>
#include <kao2ar/Archive.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eElectricity interface
    // <kao2.00567360> (constructor)
    // <kao2.00567430> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_ELECTRICITY_TYPEINFO
    (
        E_ELECTRICITY_ID,
        "eElectricity",
        &E_GADGET_TYPEINFO,
        []() -> eObject*
        {
            return new eElectricity;
        }
    );

    TypeInfo* eElectricity::getType()
    {
        return &E_ELECTRICITY_TYPEINFO;
    }

    eElectricity::eElectricity()
    : Gadget()
    {}

    eElectricity::~eElectricity() {}

}
