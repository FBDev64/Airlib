#if defined(__WIN32)

#define STB_IMAGE_IMPLEMENTATION
#include "../../../include/stb_image.h"
#include "../../../include/stb_easyfont.h"

#include "../../../include/video.h"
#include "../../../include/io.h"

#include <windows.h>
#include <GL/gl.h>
#include <stdio.h>

#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif

// Global variables for window and OpenGL
static HWND hwnd;
static HDC hdc;
static HGLRC hglrc;
static int should_close = 0;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            should_close = 1;
        PostQuitMessage(0);
        return 0;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

__declspec(dllexport) void pollEvents(void) {
    MSG msg;
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            should_close = 1;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

__declspec(dllexport) int shouldClose(void) {
    return should_close;
}

void create(int width, int height, const char* title) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "OpenGL_Window";
    RegisterClass(&wc);

    hwnd = CreateWindowEx(
        0, wc.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, wc.hInstance, NULL
    );

    hdc = GetDC(hwnd);

    PIXELFORMATDESCRIPTOR pfd =
{
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
        PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
        32,                   // Colordepth of the framebuffer.
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        24,                   // Number of bits for the depthbuffer
        8,                    // Number of bits for the stencilbuffer
        0,                    // Number of Aux buffers in the framebuffer.
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixelFormat, &pfd);

    hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);

    // OpenGL initialization
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);  // Ensure this matches your window dimensions
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Add after glLoadIdentity();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set white background

}

__declspec(dllexport) void swapBuffers(void) {
    SwapBuffers(hdc);
}

__declspec(dllexport) GLuint loadTexture(const char* filename) {
    // Step 1: Load image data
    int width, height, channels;
    unsigned char* imageData = stbi_load(filename, &width, &height, &channels, STBI_rgb_alpha);
    if (!imageData) {
        printf("Failed to load texture: %s\n", filename);
        return 0;
    }

    // Step 2: Generate and bind texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Step 3: Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Step 4: Upload texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    // Step 5: Free image data and return
    stbi_image_free(imageData);

    return textureID;
}

__declspec(dllexport) void drawTexture(GLuint textureID, float x, float y, float width, float height) {
    // Step 1: Save states
    glPushAttrib(GL_CURRENT_BIT | GL_TEXTURE_BIT);

    // Step 2: Enable texturing
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Step 3: Bind texture and set color
    glBindTexture(GL_TEXTURE_2D, textureID);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    // Step 4: Draw textured quad
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(x + width, y);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(x + width, y + height);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y + height);
    glEnd();

    // Step 5: Restore states
    glPopAttrib();

    // Disable blending after texture drawing
    glDisable(GL_BLEND);
    // After window->drawTexture call:
    glDisable(GL_TEXTURE_2D);
}

__declspec(dllexport) void drawText(float x, float y, const char* text, unsigned char* color) {
    // 1. Save current OpenGL state
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    // 2. Set text color
    glColor3ub(color[0], color[1], color[2]);

    // 3. Setup vertex buffer for font rendering
    static char vertex_buffer[99999];

    // 4. Configure font spacing and scale
    stb_easy_font_spacing(0.6f);  // Adjust character spacing
    float scale = 1.2f;  // Scale factor for text size

    // 5. Transform to correct position and scale
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f);

    // 6. Render text
    int num_quads = stb_easy_font_print(0, 0, (char*)text, NULL, vertex_buffer, sizeof(vertex_buffer));

    // 7. Setup vertex array and render
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 16, vertex_buffer);
    glDrawArrays(GL_QUADS, 0, num_quads * 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    // 8. Restore OpenGL state
    glPopAttrib();
    glPopMatrix();
}


__declspec(dllexport) void destroy(void) {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hglrc);
    ReleaseDC(hwnd, hdc);
    DestroyWindow(hwnd);
}

__declspec(dllexport) void drawButton(float x, float y, float width, float height, const char* label) {
    // Draw button background
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    // Draw button text centered
    float textX = x + (width - strlen(label) * 8) / 2;  // Approximate character width
    float textY = y + (height - 12) / 2;  // Approximate character height
    unsigned char textColor[3] = {0, 0, 0};  // Black text
    drawText(textX, textY, label, textColor);
}

__declspec(dllexport) int isButtonClicked(float x, float y, float width, float height) {
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(hwnd, &p);

        if (p.x >= x && p.x <= x + width &&
            p.y >= y && p.y <= y + height) {
            return 1;
            }
    }
    return 0;
}

__declspec(dllexport) void checkGLError() {
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR){
        printf("%s", err);
    }
}

__declspec(dllexport) Win* createWindowInstance(void) {
    static Win window = {
        .create = create,
        .pollEvents = pollEvents,
        .swapBuffers = swapBuffers,
        .shouldClose = shouldClose,
        .drawText = drawText,
        .drawButton = drawButton,
        .isButtonClicked = isButtonClicked,
        .destroy = destroy,
        .loadTexture = loadTexture,
        .drawTexture = drawTexture,
        .checkGLError = checkGLError,
        .vdl_isKeyPressed = vdl_isKeyPressed
    };
    return &window;
}

#endif