#include <kao2engine/eLineEmiter.h>
#include <kao2ar/Archive.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eLineEmiter interface
    // <kao2.00552610> (constructor)
    // <kao2.00552770> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_LINEEMITER_TYPEINFO
    (
        E_LINEEMITER_ID,
        "eLineEmiter",
        &E_PARTICLEEMITER_TYPEINFO,
        []() -> eObject*
        {
            return new eLineEmiter;
        }
    );

    TypeInfo* eLineEmiter::getType()
    {
        return &E_LINEEMITER_TYPEINFO;
    }

    eLineEmiter::eLineEmiter()
    : eParticleEmiter()
    {
        /*[0x021C]*/ unknown_021C = 128.0f;
        
        /*[0x0054]*/ unknown_0054 = 360.0f;
        /*[0x0050]*/ unknown_0050 = 30.0f;
    }

    eLineEmiter::~eLineEmiter() {}


    ////////////////////////////////////////////////////////////////
    // eLineEmiter serialization
    // <kao2.00552AE0>
    ////////////////////////////////////////////////////////////////
    void eLineEmiter::serialize(Archive &ar)
    {
        eParticleEmiter::serialize(ar);

        /* unknown values */

        ar.readOrWrite(&unknown_021C, 0x04);

        ar.readOrWrite(&unknown_0220, 0x04);
        ar.readOrWrite(&unknown_0224, 0x04);
        ar.readOrWrite(&unknown_0228, 0x04);

        ar.readOrWrite(&unknown_022C, 0x04);
        ar.readOrWrite(&unknown_0230, 0x04);
        ar.readOrWrite(&unknown_0234, 0x04);
    }

}
