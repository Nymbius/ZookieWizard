#ifndef H_KAO2AR_STRING
#define H_KAO2AR_STRING

#include <cstring> // `std::memcpy`

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // Klasay napis�w w KAO2/KAO3
    ////////////////////////////////////////////////////////////////

    template <typename charT>
    class eStringBase
    {
        /*** Properties ***/
        
        private:

            int refCount;
            int length;
            charT* text;

        /*** Methods ***/
        
        public:
            
            /* Konstrukcja klasy */
            eStringBase<charT>(int count);

            /* Usuwanie, modyfikowanie referencji */
            ~eStringBase();
            eStringBase<charT>* decRef();
            void incRef();

            /* Odwo�ania do warto�ci prywatnych */
            charT* getText() const;
            int getLength() const;
            int getReferenceCount() const;
    };

    template <typename charT>
    class eStringPtrBase
    {
        /*** eString pointer wrapper ***/
        
        private:

            eStringBase<charT>* pString;
            
        /*** Methods ***/
        
        public:
        
            /* Retrieve or set pointer - used with Archives */
            eStringBase<charT>* getPointer() const;
            void setPointer(eStringBase<charT>*  newPtr);

            /* Funkcje zwi�zane z konstrukcj� */
            void create(int count);
            void create(const charT* str);
            void copy(const eStringPtrBase<charT>& str);

            /* Modyfikowanie referencji */
            void decRef();
            void incRef();

            /* Funkcje zwi�zane z konstrukcj� i dekonstrukcj� */
            eStringPtrBase<charT>(int count = (-1));
            eStringPtrBase<charT>(const charT* str);
            eStringPtrBase<charT>(const eStringPtrBase<charT>& str);
            ~eStringPtrBase();

            /* Odwo�ania do warto�ci prywatnych */
            charT* getText() const;
            int getLength() const;
            int getReferenceCount() const;

            /* R�ne funkcje operuj�ce na tekstach */
            bool compare(const charT* str, int pos = 0, int count = 0, bool case_sensitive = false) const;
            bool compare(const eStringPtrBase<charT>& str, int pos = 0, int count = 0, bool case_sensitive = false) const;
            bool hasExtension(const charT* str) const;
            eStringPtrBase<charT> getSubstring(int pos, int count = 0) const;
            eStringPtrBase<charT> getFilename() const;

            /* Operatory przypisywania i kopiowania */
            eStringPtrBase<charT>& operator = (const charT* str);
            eStringPtrBase<charT>& operator = (const eStringPtrBase<charT>& str);
            eStringPtrBase<charT> operator + (const charT* str);
            eStringPtrBase<charT> operator + (const eStringPtrBase<charT>& str);
            eStringPtrBase<charT>& operator += (const charT* str);
            eStringPtrBase<charT>& operator += (const eStringPtrBase<charT>& str);
    };


    ////////////////////////////////////////////////////////////////
    // Definicje u�ywanych typ�w tekstu
    ////////////////////////////////////////////////////////////////

    typedef eStringPtrBase<char> eString;
    typedef eStringPtrBase<wchar_t> eUnicodeString;


    ////////////////////////////////////////////////////////////////
    // Dodatkowe funkcje szblonowe
    ////////////////////////////////////////////////////////////////

    namespace StringFunctions
    {
        void convertString(eString& str1, const eUnicodeString& str2);
        void convertString(eUnicodeString& str1, const eString& str2);

        template <typename charT>
        int getCharArrayLength(const charT* str);

        template <typename charT>
        charT toLowerCase(charT x);
    }

}
    
#endif
