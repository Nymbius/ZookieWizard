#include <kao2engine/VoidInstruction.h>
#include <kao2ar/Archive.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // VoidInstruction interface
    // <kao2.0058C1E0> (constructor)
    // <kao2.0058C290> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_VOIDINSTRUCTION_TYPEINFO
    (
        E_VOIDINSTRUCTION_ID,
        "VoidInstruction",
        &E_REFCOUNTER_TYPEINFO,
        []() -> eObject*
        {
            return nullptr;
        }
    );

    TypeInfo* VoidInstruction::getType()
    {
        return &E_VOIDINSTRUCTION_TYPEINFO;
    }

    VoidInstruction::VoidInstruction()
    : eRefCounter()
    {}

    VoidInstruction::~VoidInstruction() {}

}
