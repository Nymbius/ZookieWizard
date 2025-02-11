#ifndef H_KAO2AR_SIMPLECR
#define H_KAO2AR_SIMPLECR

#include <kao2engine/Gadget.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eSimpleCR interface
    // <kao2.005D5200> (vptr)
    ////////////////////////////////////////////////////////////////

    class eSimpleCR : public Gadget
    {

        /*** Properties ***/

        protected:

            /*[0x0010]*/
            /*(...)*/
            /*[0x018C]*/

        /*** Methods ***/

        public:

            eSimpleCR();
            ~eSimpleCR();

            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eSimpleCR TypeInfo
    // <kao2.0051C770> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_SIMPLECR_ID = 0x3C4B9205;

    extern TypeInfo E_SIMPLECR_TYPEINFO;

}

#endif
