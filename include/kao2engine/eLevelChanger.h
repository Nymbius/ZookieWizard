#ifndef H_KAO2AR_LEVELCHANGER
#define H_KAO2AR_LEVELCHANGER

#include <kao2engine/Gadget.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eLevelChanger interface
    ////////////////////////////////////////////////////////////////

    class eLevelChanger : public Gadget
    {
        /*** Methods ***/

        public:

            eLevelChanger();
            ~eLevelChanger();

            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eLevelChanger TypeInfo
    // <kao2.00457840> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_LEVELCHANGER_ID = 0x3D2646A2;

    extern TypeInfo E_LEVELCHANGER_TYPEINFO;

}

#endif
