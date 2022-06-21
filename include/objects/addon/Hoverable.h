#pragma once
#include "../../events/Event.h"

class Hoverable : Event {
public:
    Hoverable(SDL_Rect* controller, bool isActive) : Event() {
        controllerRect = controller;
        if (!isActive)
            EventHandler::unregisterEvent(this);
    }
    void onEvent(SDL_Event* event) override {
        if (event->type == SDL_MOUSEMOTION) {
            SDL_GetMouseState(&mx, &my);
            SDL_Rect mouseRect = {mx, my, 1, 1};
            if (SDL_HasIntersection(controllerRect, &mouseRect))
                onHover();
        }
    }
    virtual void onHover() {}
    
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