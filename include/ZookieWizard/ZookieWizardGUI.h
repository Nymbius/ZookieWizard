#ifndef H_ZOOKIEWIZARD_GUI
#define H_ZOOKIEWIZARD_GUI

namespace ZookieWizard
{

    ////////////////////////////////////////////////////////////////
    // Graphical User Interface
    ////////////////////////////////////////////////////////////////

    namespace GUI
    {
        /*** Defines and variables ***/

            #include <ZookieWizard/GUI_defines.h>

            struct testCameraStruct
            {
                double pos_x;
                double pos_y;
                double pos_z;

                double look_x;
                double look_y;
                double look_z;

                double pitch;
                double yaw;

                testCameraStruct();
                void reset();
            };

            extern HWND myWindowsGroupMain[2];
            extern HWND myWindowsGroupAr[7];
            extern HWND myWindowsGroupDenis[4];

            extern int32_t myWindowsCurrentGroup;

            extern HBITMAP myWindowsLogo;
            extern HFONT myWindowsFont;
            extern HDC openGL_DeviceContext;
            extern HGLRC openGL_RenderingContext;

            extern int32_t mousePosAndButton[3];
            extern float backgroundColor[3];
            extern bool isOrthoMode;
            extern testCameraStruct testCamera;

            enum drawFlags
            {
                DRAW_FLAG_INVISIBLE = (1 << 0),
                DRAW_FLAG_BOXZONES = (1 << 1),
                DRAW_FLAG_PROXIES = (1 << 2),

                DRAW_FLAGS_COUNT = 3
            };

            extern int32_t myDrawFlags;

        /*** Functions ***/

            bool createWindows(HINSTANCE hInstance);
            bool prepareRendering();

            LRESULT CALLBACK procedureOfRenderWindow(HWND, UINT, WPARAM, LPARAM);
            LRESULT CALLBACK procedureOfMainWindow(HWND, UINT, WPARAM, LPARAM);

            bool isAppRunning();
            void render();
            void setPerspective(GLsizei, GLsizei);
            void changeView(bool);
            void moveCameraAndLook(int32_t, int32_t);
            
            void closeWindows();
            void changeWindowGroup();
    }
}

#endif
