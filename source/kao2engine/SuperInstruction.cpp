#include <kao2engine/SuperInstruction.h>
#include <kao2ar/Archive.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // SuperInstruction interface
    // <kao2.0058FC30> (constructor)
    // <kao2.0058FD20> (destructor)
    ////////////////////////////////////////////////////////////////

    TypeInfo E_SUPERINSTRUCTION_TYPEINFO
    (
        E_SUPERINSTRUCTION_ID,
        "SuperInstruction",
        &E_VOIDINSTRUCTION_TYPEINFO,
        []() -> eObject*
        {
            return new SuperInstruction(nullptr);
        }
    );

    TypeInfo* SuperInstruction::getType()
    {
        return &E_SUPERINSTRUCTION_TYPEINFO;
    }

    SuperInstruction::SuperInstruction(VoidInstruction* x)
    : VoidInstruction()
    {
        /*[0x08]*/ unknown_08 = x;

        if (nullptr != x)
        {
            x->incRef();
        }
    }

    SuperInstruction::~SuperInstruction()
    {
        if (nullptr != unknown_08)
        {
            unknown_08->decRef();
        }
    }


    ////////////////////////////////////////////////////////////////
    // SuperInstruction serialization
    // <kao2.0058FEF0>
    ////////////////////////////////////////////////////////////////
    void SuperInstruction::serialize(Archive &ar)
    {
        /* [0x08] unknown */

        ArFunctions::serialize_eRefCounter(ar, (eRefCounter**)&unknown_08, &E_VOIDINSTRUCTION_TYPEINFO);
    }


    ////////////////////////////////////////////////////////////////
    // SuperInstruction: save to text file
    ////////////////////////////////////////////////////////////////
    void SuperInstruction::saveInstructionToTextFile(FileOperator &file, int32_t indentation)
    {
        ArFunctions::writeNewLine(file, 0);

        ArFunctions::writeNewLine(file, indentation);

        file << "/* super */";

        if (nullptr != unknown_08)
        {
            unknown_08->saveInstructionToTextFile(file, (indentation + 1));
        }

        ArFunctions::writeNewLine(file, 0);
    }

}
