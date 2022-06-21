#pragma once
#include "../../events/Event.h"

class Clickable : Event {
public:
    Clickable(SDL_Rect* controller, bool isActive) : Event() {
        controllerRect = controller;
        if (!isActive)
            EventHandler::unregisterEvent(this);
    }
    void onEvent(SDL_Event* event) override {
        if (event->type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&mx, &my);
            SDL_Rect mouseRect = {mx, my, 1, 1};
            if (SDL_HasIntersection(controllerRect, &mouseRect))
                onClick();
        }
    }
    virtual void onClick() {}
    
    void setActive() {
        EventHandler::registerEvent(this);
    }
    void setInactive() {
        EventHandler::unregisterEvent(this);
    }
private:
    int mx, my;
    SDL_Rect* controllerRect;
};