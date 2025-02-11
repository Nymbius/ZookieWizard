#ifndef H_KAO2AR_SCENE
#define H_KAO2AR_SCENE

#include <kao2engine/ePivot.h>

#include <kao2engine/eCollisionMgr.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eScene portal structures
    ////////////////////////////////////////////////////////////////

    struct ScenePortalBaseA
    {
        /*** Properties ***/

            /*[0x00]*/ uint8_t unknown_00;
            /*[0x01]*/ uint8_t unknown_01;
            /*[0x02]*/ uint8_t unknown_02;

            /*[0x04-0x0C]*/ ePoint3 unknown_04;
            /*[0x10-0x18]*/ ePoint3 unknown_10;
            /*[0x1C-0x24]*/ ePoint3 unknown_1C;

            /*[0x28]*/ eString unknown_28;

        /*** Methods ***/

            void serialize(Archive &ar);
    };

    struct ScenePortalBaseB
    {
        /*** Properties ***/

            /*[0x00]*/ int32_t unknown_00;
            /*[0x04]*/ eString name;

            /*[0x08]*/ int32_t groupA_count;
            /*[0x0C]*/ int32_t groupA_maxLength;
            /*[0x10]*/ ePoint4* groupA;

            /*[0x14]*/ int32_t groupB_count;
            /*[0x18]*/ int32_t groupB_maxLength;
            /*[0x1C]*/ uint8_t* groupB;

        /*** Methods ***/

            ScenePortalBaseB();
            ~ScenePortalBaseB();

            void serialize(Archive &ar);
    };


    ////////////////////////////////////////////////////////////////
    // eScene interface
    ////////////////////////////////////////////////////////////////

    class eScene : public ePivot
    {

        /*** Properties ***/

        protected:

            /*[0x0114-0x0158]*/ eCollisionMgr collision;
            /*[0x015C-0x016C]*/ // (not serialized, eEventSys)
            /*[0x0170-0x0178]*/ GLfloat color[3]; // `glClearColor()`
            /*[0x017C-0x0188]*/ GLfloat ambient[4]; // `glLightModelfv()`
            /*[0x18C]*/ eString compileStrA;
            /*[0x190]*/ eString compileStrB;
            /*[0x194-0x19C]*/ Collection<ArFunctions::serialize_eRefCounter> unknown0194;

            /*(kao3)[0x026C]*/

            /*(kao3)[0x029C-0x02A4]*/ Collection<ArFunctions::serialize_eRefCounter> visGroups;
            /*(kao3)[0x02A8]*/ uint8_t visGroups_unknown;

            /*(kao3)[0x02AC]*/ int32_t visSetA_count;
            /*(kao3)[0x02B0]*/ int32_t visSetA_maxLength;
            /*(kao3)[0x02B4]*/ ScenePortalBaseA* visSetA;

            /*(kao3)[0x02B8]*/ int32_t visSetB_count;
            /*(kao3)[0x02BC]*/ int32_t visSetB_maxLength;
            /*(kao3)[0x02C0]*/ ScenePortalBaseB* visSetB;

        /*** Methods ***/

        private:

            void function_00498B20();

        public:

            eScene();
            ~eScene();

            void serialize(Archive &ar) override;
            TypeInfo* getType() override;

            void setBackgroundColor(GLfloat new_color[3]);
            void setCompileStrings(eString str_a, eString str_b);

            eCollisionMgr* getCollisionManager();
    };


    ////////////////////////////////////////////////////////////////
    // eScene TypeInfo
    // <kao2.0x00499F90> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_SCENE_ID = 0x8001;

    extern TypeInfo E_SCENE_TYPEINFO;


    ////////////////////////////////////////////////////////////////
    // Global Scene pointer
    ////////////////////////////////////////////////////////////////

    namespace ArFunctions
    {
        void setCurrentScene(eScene* scene);
        eScene* getCurrentScene();
    }

    extern eScene* theScene;

}

#endif
