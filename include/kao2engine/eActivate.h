#ifndef H_KAO2AR_ACTIVATE
#define H_KAO2AR_ACTIVATE

#include <kao2engine/Gadget.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eActivate interface
    // <kao2.005D8780> (vptr)
    ////////////////////////////////////////////////////////////////

    class eActivate : public Gadget
    {

        /*** Properties ***/

        protected:

            /*[0x10]*/

        /*** Methods ***/

        public:

            eActivate();
            ~eActivate();

            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eActivate TypeInfo
    // <kao2.005A3480> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_ACTIVATE_ID = 0x358E5A86;

    extern TypeInfo E_ACTIVATE_TYPEINFO;

}

#endif
