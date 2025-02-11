#ifndef H_KAO2AR_NPCMAP
#define H_KAO2AR_NPCMAP

#include <kao2engine/eGroup.h>

#include <kao2engine/eGroupManager.h>

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // eNPCMap interface
    // <kao2.005CE078> (vptr)
    ////////////////////////////////////////////////////////////////

    class eNPCMap : public eGroup
    {

        /*** Properties ***/

        protected:

            /*[0x48]*/ uint8_t unknown_48;
            /*[0x4C]*/ int32_t unknown_4C;
            /*[0x50]*/ int32_t unknown_50;
            /*[0x54]*/ float unknown_54;
            /*[0x58]*/ float unknown_58;
            /*[0x5C]*/ float unknown_5C;
            /*[0x60]*/ int32_t* unknown_60;
            /*[0x64-0x6C]*/ ePoint3 unknown_64;
            /*[0x70-0x78]*/ ePoint3 unknown_70;
            /*[0x7C-0x98]*/ eGroupManager unknown_7C;

            /*[0x9C]*/ int32_t groupA_Count;
            /*[0xA0]*/ int32_t groupA_MaxLength;
            /*[0xA4]*/ int32_t* groupA;

            /*[0xA8]*/ int32_t unknown_A8;
            /*[0xAC]*/ float unknown_AC;
            /*[0xB0]*/ float unknown_B0;
            /*[0xB4]*/ float unknown_B4;

            /*(...)*/

            /*[0xBC]*/
            /*[0xC0]*/
            /*[0xC4]*/

        /*** Methods ***/

        public:

            eNPCMap();
            ~eNPCMap();

            void serialize(Archive &ar) override;
            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eNPCMap TypeInfo
    // <kao2.00422660> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_NPCMAP_ID = 0xA10000FF;

    extern TypeInfo E_NPCMAP_TYPEINFO;

}

#endif
