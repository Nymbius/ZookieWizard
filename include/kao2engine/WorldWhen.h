#ifndef H_KAO2AR_WORLDWHEN
#define H_KAO2AR_WORLDWHEN

#include <kao2engine/When.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // WorldWhen interface
    ////////////////////////////////////////////////////////////////

    class WorldWhen : public When
    {
        /*** Methods ***/

        public:

            WorldWhen();
            ~WorldWhen();

            TypeInfo* getType() override;
            
            void saveWhenToTextFile(FileOperator &file, int32_t indentation) override;
    };


    ////////////////////////////////////////////////////////////////
    // WorldWhen TypeInfo
    // <kao2.0059E560> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_WORLDWHEN_ID = 0x0002204D;

    extern TypeInfo E_WORLDWHEN_TYPEINFO;

}

#endif
