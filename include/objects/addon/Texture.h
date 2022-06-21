#pragma once
#include "Renderable.h"

class Texture : public Renderable {

public:
    Texture(const char* texturePath, int x, int y, int w, int h) : Renderable(x, y, w, h) {
        texture = Renderer::loadTexture(texturePath);
        srcRect = {0, 0, w, h};
    }

    Texture(const char* texturePath, int x, int y, int w, int h, int s_x, int s_y) : Renderable(x, y, w, h) {
        texture = Renderer::loadTexture(texturePath);
        destRect = {x, y, w, h};
        srcRect = {s_x, s_y, w, h};
    }

    void render() override {
        Renderer::renderTexture(texture, &srcRect, &destRect);
    }
    ~Texture() {
        SDL_DestroyTexture(texture);
    }

    const int sy() {
        return destRect.y;
    }

    const int sw() {
        return destRect.w;
    }

    const int sh() {
        return destRect.h;
    }

    void sx(const int x) {
        destRect.x = x;
    }

    void sy(const int y) {
        destRect.y = y;
    }

    void sw(const int w) {
        destRect.w = w;
    }

    void sh(const int h) {
        destRect.h = h;
    }

    SDL_Texture* getTexture() {
        return texture;
    }

    void setTexture(const char* texturePath) {
        texture = Renderer::loadTexture(texturePath);
    }

protected:
    SDL_Texture* texture;
    SDL_Rect srcRect /*destRect*/;
};