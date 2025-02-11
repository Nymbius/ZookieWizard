#ifndef H_KAO2AR_NAVIPOINT
#define H_KAO2AR_NAVIPOINT

#include <kao2engine/eTransform.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eNaviPoint interface
    // <kao2.005D0358> (vptr)
    ////////////////////////////////////////////////////////////////

    class eNaviPoint : public eTransform
    {

        /*** Methods ***/

        public:

            eNaviPoint();
            ~eNaviPoint();

            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eNaviPoint TypeInfo
    // <kao2.00429CF0> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_NAVIPOINT_ID = 0xFACEFACE;

    extern TypeInfo E_NAVIPOINT_TYPEINFO;

}

#endif
