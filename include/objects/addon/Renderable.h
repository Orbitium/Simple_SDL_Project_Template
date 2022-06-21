#pragma once
#include <SDL_rect.h>

#include "../../Renderer.h"

class Renderable {
public:
    Renderable(int x, int y, int w, int h) {
        destRect = {x, y, w, h};
    }

    virtual void render() {
        Renderer::renderRect(&destRect);
    }
    
    const int dx() {
        return destRect.x;
    }

    const int dy() {
        return destRect.y;
    }

    const int dw() {
        return destRect.w;
    }

    const int dh() {
        return destRect.h;
    }

    void dx(const int x) {
        destRect.x = x;
    }

    void dy(const int y) {
        destRect.y = y;
    }

    void dw(const int w) {
        destRect.w = w;
    }

    void dh(const int h) {
        destRect.h = h;
    }

    SDL_Rect* getDestRect() {
        return &destRect;
    }
protected:
    SDL_Rect destRect;
};