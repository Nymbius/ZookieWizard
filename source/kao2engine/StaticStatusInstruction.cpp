#include <kao2engine/StaticStatusInstruction.h>
#include <kao2ar/Archive.h>

#include <kao2ar/StaticPool.h>
#include <kao2engine/Gadget.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // StaticStatusInstruction interface
    // <kao2.0058E110> (constructor)
    // <kao2.0058E1A0> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_STATICSTATUSINSTRUCTION_TYPEINFO
    (
        E_STATICSTATUSINSTRUCTION_ID,
        "StaticStatusInstruction",
        &E_BASESTATUSINSTRUCTION_TYPEINFO,
        []() -> eObject*
        {
            return new StaticStatusInstruction;
        }
    );

    TypeInfo* StaticStatusInstruction::getType()
    {
        return &E_STATICSTATUSINSTRUCTION_TYPEINFO;
    }

    StaticStatusInstruction::StaticStatusInstruction()
    : BaseStatusInstruction()
    {
        /*[0x10]*/ link = nullptr;
    }

    StaticStatusInstruction::~StaticStatusInstruction() {}


    ////////////////////////////////////////////////////////////////
    // StaticStatusInstruction serialization
    // <kao2.0058E270>
    ////////////////////////////////////////////////////////////////
    void StaticStatusInstruction::serialize(Archive &ar)
    {
        StaticPool.serializeGadget(ar, &link);

        BaseStatusInstruction::serialize(ar);
    }


    ////////////////////////////////////////////////////////////////
    // StaticStatusInstruction: get script representation
    ////////////////////////////////////////////////////////////////
    eString StaticStatusInstruction::generateScriptText()
    {
        eString result;

        if (nullptr != link)
        {
            result += link->getStringRepresentation();
        }
        else
        {
            result += "< EMPTY_GADGET >";
        }

        result += ".";
        result += unknown_08;
        result += "(";

        if (nullptr != unknown_0C)
        {
            result += unknown_0C->getStringRepresentation();
        }

        result += ")";

        return result;
    }

}
