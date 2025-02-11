#include <kao2engine/eActionTable.h>
#include <kao2ar/Archive.h>

#include <kao2engine/eNode.h>
#include <kao2engine/eCameraZonePacket.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eActionTable interface
    // <kao2.004AF9A9> (constructor)
    // <kao2.0049D6F0> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_ACTIONTABLE_TYPEINFO
    (
        E_ACTIONTABLE_ID,
        "eActionTable",
        &E_REFCOUNTER_TYPEINFO,
        []() -> eObject*
        {
            return new eActionTable;
        }
    );

    TypeInfo* eActionTable::getType()
    {
        return &E_ACTIONTABLE_TYPEINFO;
    }

    eActionTable::eActionTable()
    : eRefCounter()
    {
        /*[0x08]*/ actionsCount = 0;
        /*[0x0C]*/ actionsMaxLength = 0;
        /*[0x10]*/ actions = nullptr;
    }

    eActionTable::~eActionTable()
    {
        if (nullptr != actions)
        {
            delete[](actions);
        }
    }


    ////////////////////////////////////////////////////////////////
    // Action Structure
    // <kao2.004AF0C0> (constructor)
    // <kao2.004AF470> (serialization)
    ////////////////////////////////////////////////////////////////

    eActionBase::eActionBase()
    {
        /*[0x04]*/ nodeTarget = nullptr;
        /*[0x0C]*/ cameraPacket = nullptr;
        /*[0x10]*/ unknown_10 = 0;
        /*[0x14]*/ unknown_14 = 0x00;
        /*[0x15]*/ unknown_15 = 0x01;
    }

    eActionBase::~eActionBase()
    {
        /*[0x0C]*/ cameraPacket->decRef();
        /*[0x04]*/ nodeTarget->decRef();
    }

    void eActionBase::serializeAction(Archive &ar)
    {
        /* [0x04] The actor who receives the message */
        ArFunctions::serialize_eRefCounter(ar, (eRefCounter**)&nodeTarget, &E_NODE_TYPEINFO);

        /* [0x18] If actor doesn't exits in this scene, serialize its name */
        if (nullptr == nodeTarget)
        {
            ar.serializeString(actorName);
        }
        else
        {
            actorName = "";
        }

        /* [0x08] The message to send */
        ar.serializeString(message);

        /* [0x0C] Camera? */
        ArFunctions::serialize_eRefCounter(ar, (eRefCounter**)&cameraPacket, &E_CAMERAZONEPACKET_TYPEINFO);

        /* [0x10] Unknown values */
        ar.readOrWrite(&unknown_10, 0x04);
        ar.readOrWrite(&unknown_14, 0x01);
        ar.readOrWrite(&unknown_15, 0x01);
    }


    ////////////////////////////////////////////////////////////////
    // eActionTable serialization
    // <kao2.004AF910>
    ////////////////////////////////////////////////////////////////
    void eActionTable::serialize(Archive &ar)
    {
        int32_t i;

        if (ar.isInReadMode())
        {
            if (nullptr != actions)
            {
                delete[](actions);
            }

            ar.readOrWrite(&actionsMaxLength, 0x04);

            actions = new eActionBase [actionsMaxLength];

            for (i = 0; i < actionsMaxLength; i++)
            {
                actions[i].serializeAction(ar);

                actionsCount = (i+1);
            }
        }
        else
        {
            ar.readOrWrite(&actionsCount, 0x04);

            for (i = 0; i < actionsCount; i++)
            {
                actions[i].serializeAction(ar);
            }
        }
    }

}
