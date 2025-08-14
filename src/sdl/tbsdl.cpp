#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_tray.h>
#include <SDL3/SDL_video.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <tbsdl.h>
#include <tblib.h>

tbwin::tbwin(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font) {
    window = win;
    renderer = ren;
    font = tbwin::font;
}
void tbwin::tbloop() const {
    if (currText.size() > 0 && prevSize != currText.size()) {
        SDL_Surface* textSurface = TTF_RenderText_LCD_Wrapped(font, currText.c_str(), currText.size(), fg, bg, 600);
        SDL_FRect rect{x, y, static_cast<float>(textSurface->w), static_cast<float>(textSurface->h)};
        SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, textSurface);
        SDL_DestroySurface(textSurface);
        SDL_RenderTexture(ren, texture, NULL, &rect);
        SDL_DestroyTexture(texture);
    }
}

void tbwin::tbclear() {
    currText = "";
}
