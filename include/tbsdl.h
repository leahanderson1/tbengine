#ifndef TBSDL_H
#define TBSDL_H
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_tray.h>
#include <SDL3/SDL_video.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstddef>
#include <string>
#include <tblib.h>

class tbwin {
    private:
        SDL_Window *win;
        SDL_Renderer *ren;
        TTF_Font *font;
        std::size_t prevSize;
    public:
        std::string currText;
        SDL_Color fg = { 255, 255, 255, 255 };
        SDL_Color bg = { 0, 0, 0, 255 };
        float x = 5;
        float y = 50;
        tbwin(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font);
        void tbloop() const;
        void tbclear();
        void tbout(Text text, bool vn, unsigned int ms);
};
#endif
