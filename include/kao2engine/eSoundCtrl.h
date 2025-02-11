#ifndef H_KAO2AR_SOUNDCTRL
#define H_KAO2AR_SOUNDCTRL

#include <kao2engine/eCtrlBase.h>

namespace ZookieWizard
{
    ////////////////////////////////////////////////////////////////
    // Sound Key
    ////////////////////////////////////////////////////////////////

    struct eSoundKeyBase
    {
        /*** Properties ***/

            /*[0x00]*/ float time;
            /*[0x04]*/ eString sampleName;
            /*[0x08]*/ float volume;
            /*[0x0C]*/ bool unknown_0C;

        /*** Methods ***/

            eSoundKeyBase();

            void serializeSoundKey(Archive &ar);
    };

    ////////////////////////////////////////////////////////////////
    // eSoundCtrl interface
    ////////////////////////////////////////////////////////////////

    class eSoundCtrl : public eCtrlBase
    {

        /*** Properties ***/

        protected:

            /*[0x08-0x14]*/ float unknown_08[4];
            
            /*[0x18]*/ int32_t keysCount;
            /*[0x1C]*/ int32_t keysMaxLength;
            /*[0x20]*/ eSoundKeyBase* keys;

        /*** Methods ***/

        public:

            eSoundCtrl();
            ~eSoundCtrl();

            void serialize(Archive &ar) override;
            TypeInfo* getType() override;
    };


    ////////////////////////////////////////////////////////////////
    // eSoundCtrl TypeInfo
    // <kao2.0056D660> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_SOUNDCTRL_ID = 0x44444555;

    extern TypeInfo E_SOUNDCTRL_TYPEINFO;

}

#endif
