#ifndef H_KAO2AR_GEOMETRY
#define H_KAO2AR_GEOMETRY

#include <kao2engine/eNode.h>

namespace ZookieWizard
{
    class eMaterial;

    ////////////////////////////////////////////////////////////////
    // eGeometry interface
    ////////////////////////////////////////////////////////////////

    class eGeometry : public eNode
    {

        /*** Properties ***/

        protected:

            /*[0x3C]*/ eMaterial* material;
            /*[0x40-0x48]*/ ePoint3 boxBoundMin;
            /*[0x4C-0x54]*/ ePoint3 boxBoundMax;

        /*** Methods ***/

        public:

            eGeometry(eString s, eNode* x);
            eGeometry();
            ~eGeometry();

            void serialize(Archive &ar) override;
            TypeInfo* getType() override;

            void oldNodeSerialization(ePoint3* arg1);
    };


    ////////////////////////////////////////////////////////////////
    // eGeometry TypeInfo
    // <kao2.0046FA50> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_GEOMETRY_ID = 0x034567FD;

    extern TypeInfo E_GEOMETRY_TYPEINFO;

}

#endif
