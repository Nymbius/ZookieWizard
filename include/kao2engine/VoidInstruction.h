#ifndef H_KAO2AR_VOIDINSTRUCTION
#define H_KAO2AR_VOIDINSTRUCTION

#include <kao2engine/eRefCounter.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // VoidInstruction interface
    ////////////////////////////////////////////////////////////////

    class VoidInstruction : public eRefCounter
    {
        /*** Methods ***/

        public:

            VoidInstruction();
            ~VoidInstruction();

            TypeInfo* getType() override;

            virtual void saveInstructionToTextFile(FileOperator &file, int32_t indentation) = 0;
    };


    ////////////////////////////////////////////////////////////////
    // VoidInstruction TypeInfo
    // <kao2.0058C3A0> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_VOIDINSTRUCTION_ID = 0x00022001;

    extern TypeInfo E_VOIDINSTRUCTION_TYPEINFO;

}

#endif
