#ifndef H_KAO2AR_TARGETGENERATOR
#define H_KAO2AR_TARGETGENERATOR

#include <kao2engine/Gadget.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eTargetGenerator interface
    // <kao2.005D8830> (vptr)
    ////////////////////////////////////////////////////////////////

    class eTargetGenerator : public Gadget
    {

        /*** Properties ***/

        protected:

            /*[0x10]*/
            /*[0x14]*/
            /*[0x18]*/
            /*[0x1C]*/

        /*** Methods ***/

        public:

            eTargetGenerator();
            ~eTargetGenerator();

            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eTargetGenerator TypeInfo
    // <kao2.005A5030> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_TARGETGENERATOR_ID = 0x3BE0ACF2;

    extern TypeInfo E_TARGETGENERATOR_TYPEINFO;

}

#endif
