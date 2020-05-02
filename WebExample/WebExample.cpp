#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include "Emscripten.h"

SDL_Window* window;

float offset = 0;

void main_loop() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glVertex2f(0.0f, 0.5f+offset);
    glVertex2f(0.5f, -0.5f+offset);
    glVertex2f(-0.5f, -0.5f+offset);

    glVertex2f(0.0f, -0.5f - offset);
    glVertex2f(0.5f, 0.5f - offset);
    glVertex2f(-0.5f, 0.5f - offset);

    glEnd();

    offset += 0.005f;

    SDL_GL_SwapWindow(window);
}

int main(int argc, char** argv)
{
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, nullptr);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    emscripten_set_main_loop(main_loop, 0, true);
}