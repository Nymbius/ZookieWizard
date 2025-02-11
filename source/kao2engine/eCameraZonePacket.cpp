#include <kao2engine/eCameraZonePacket.h>
#include <kao2ar/Archive.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eCameraZonePacket interface
    // <kao2.00514852> (constructor)
    // <kao2.005148F0> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_CAMERAZONEPACKET_TYPEINFO
    (
        E_CAMERAZONEPACKET_ID,
        "eCameraZonePacket",
        &E_REFCOUNTER_TYPEINFO,
        []() -> eObject*
        {
            return new eCameraZonePacket;
        }
    );

    TypeInfo* eCameraZonePacket::getType()
    {
        return &E_CAMERAZONEPACKET_TYPEINFO;
    }

    eCameraZonePacket::eCameraZonePacket()
    : eRefCounter()
    {
        /*[0x08]*/ unknown_08 = 0;

        /*[0x0C]*/ unknown_0C = 0;
        /*[0x10]*/ unknown_10 = 0;

        /*[0x14]*/ unknown_14 = 0;
        /*[0x18]*/ unknown_18 = 0;
        /*[0x1C]*/ unknown_1C = 0;
    }

    eCameraZonePacket::~eCameraZonePacket() {}


    ////////////////////////////////////////////////////////////////
    // eCameraZonePacket serialization
    // <kao2.00514990>
    ////////////////////////////////////////////////////////////////
    void eCameraZonePacket::serialize(Archive &ar)
    {
        /* [0x0C] unknown values */

        ar.readOrWrite(&unknown_0C, 0x04);
        ar.readOrWrite(&unknown_10, 0x04);

        if (ar.getVersion() >= 0x80)
        {
            /* [0x08] unknown values */

            ar.readOrWrite(&unknown_08, 0x04);

            if (0 != unknown_08)
            {
                /* [0x14] unknown values */

                ar.readOrWrite(&unknown_14, 0x04);
                ar.readOrWrite(&unknown_18, 0x04);
                ar.readOrWrite(&unknown_1C, 0x04);
            }
        }
    }

}
