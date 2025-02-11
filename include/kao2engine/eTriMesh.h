#ifndef H_KAO2AR_TRIMESH
#define H_KAO2AR_TRIMESH

#include <kao2engine/eGeometry.h>

namespace ZookieWizard
{
    class eGeoSet;

    ////////////////////////////////////////////////////////////////
    // eTriMesh interface
    ////////////////////////////////////////////////////////////////

    class eTriMesh : public eGeometry
    {

        /*** Properties ***/

        protected:

            /*[0x58]*/ eGeoSet* geo;

        /*** Methods ***/

        public:

            eTriMesh();
            ~eTriMesh();

            void serialize(Archive &ar) override;
            TypeInfo* getType() override;

            void renderObject(float time, int32_t draw_flags) override;

            eGeoSet* getGeoSetLink();
            void setGeoSet(eGeoSet* new_geo);
            void setMaterial(eMaterial* new_material);
            void setBoundaryBox(ePoint3 new_min, ePoint3 new_max);
    };


    ////////////////////////////////////////////////////////////////
    // eTriMesh TypeInfo
    // <kao2.0046D6F0> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_TRIMESH_ID = 0x3005;

    extern TypeInfo E_TRIMESH_TYPEINFO;

}

#endif
