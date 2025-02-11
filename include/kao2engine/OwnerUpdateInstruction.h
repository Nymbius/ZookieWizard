#ifndef H_KAO2AR_OWNERUPDATEINSTRUCTION
#define H_KAO2AR_OWNERUPDATEINSTRUCTION

#include <kao2engine/VoidInstruction.h>

namespace ZookieWizard
{
    class State;

    ////////////////////////////////////////////////////////////////
    // OwnerUpdateInstruction interface
    ////////////////////////////////////////////////////////////////

    class OwnerUpdateInstruction : public VoidInstruction
    {

        /*** Properties ***/

        protected:

            /*[0x08]*/ State* unknown_08;

        /*** Methods ***/

        public:

            OwnerUpdateInstruction(State* x);
            ~OwnerUpdateInstruction();

            void serialize(Archive &ar) override;
            TypeInfo* getType() override;

            void saveInstructionToTextFile(FileOperator &file, int32_t indentation) override;
    };


    ////////////////////////////////////////////////////////////////
    // OwnerUpdateInstruction TypeInfo
    // <kao2.005905F0> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_OWNERUPDATEINSTRUCTION_ID = 0x00022019;

    extern TypeInfo E_OWNERUPDATEINSTRUCTION_TYPEINFO;

}

#endif
