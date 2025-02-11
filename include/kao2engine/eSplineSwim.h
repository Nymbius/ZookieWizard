#ifndef H_KAO2AR_SPLINESWIM
#define H_KAO2AR_SPLINESWIM

#include <kao2engine/eSplineBase.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eSplineSwim interface
    // <kao2.005CF960> (vptr)
    ////////////////////////////////////////////////////////////////

    class eSplineSwim : public eSplineBase
    {

        /*** Properties ***/

        protected:

            /*[0x28]*/
            /*(...)*/
            /*[0x48]*/

        /*** Methods ***/

        public:

            eSplineSwim();
            ~eSplineSwim();

            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eSplineSwim TypeInfo
    // <kao2.0044C490> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_SPLINESWIM_ID = 0x3B93287C;

    extern TypeInfo E_SPLINESWIM_TYPEINFO;

}

#endif
