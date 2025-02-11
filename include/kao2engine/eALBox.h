#ifndef H_KAO2AR_ALBOX
#define H_KAO2AR_ALBOX

#include <kao2engine/eRefCounter.h>

#include <kao2ar/AxisList.h>

#include <kao2ar/Collection.h>

namespace ZookieWizard
{
    class eScene;
    class eNode;
    class eALBox;

    ////////////////////////////////////////////////////////////////
    // eALBox interface
    ////////////////////////////////////////////////////////////////

    class eALBox : public eRefCounter
    {
        /*** Properties ***/

        protected:

            /*[0x08]*/ eScene* unknown_08;
            /*[0x0C]*/ eNode* unknown_0C;

            /*[0x10-0x6F]*/ AxisList test[3][2];

            /*[0x70]*/ int32_t seriesCount;
            /*[0x74]*/ int32_t seriesMaxLength;
            /*[0x78]*/ uint8_t* series;

            /*[0x7C]*/ int32_t unknown_7C;

            /*[0x80-0x88]*/ Collection<ArFunctions::serialize_eRefCounter> unknown_80;

            /*[0x8C]*/ uint8_t unknown_8C;

        /*** Methods ***/

        protected:

            bool function_004AAB60();
            void function_004A9CC0();
            void function_004A99C0();
            void function_004A9C80();
            void function_004A9870();

        public:

            eALBox();
            ~eALBox();

            void serialize(Archive &ar) override;
            TypeInfo* getType() override;

            AxisList* getAxisList(int32_t row, int32_t column);
            uint8_t* getSeriesPointer();
    };


    ////////////////////////////////////////////////////////////////
    // eALBox TypeInfo
    // <kao2.004AAD80> (registration)
    ////////////////////////////////////////////////////////////////

    static const int E_ALBOX_ID = 0x01231325;

    extern TypeInfo E_ALBOX_TYPEINFO;

}

#endif
