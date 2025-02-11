#ifndef H_KAO2AR_STRAFECTRL
#define H_KAO2AR_STRAFECTRL

#include <kao2engine/ePathCtrl.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eStrafeCtrl interface
    // <kao2.005CF9C0> (vptr)
    ////////////////////////////////////////////////////////////////

    class eStrafeCtrl : public ePathCtrl
    {

        /*** Properties ***/

        protected:

            /*[0x50]*/
            /*(...)*/
            /*[0x94]*/

        /*** Methods ***/

        public:

            eStrafeCtrl();
            ~eStrafeCtrl();

            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eStrafeCtrl TypeInfo
    // <kao2.0044D0E0> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_STRAFECTRL_ID = 0x3A8C5FC6;

    extern TypeInfo E_STRAFECTRL_TYPEINFO;

}

#endif
