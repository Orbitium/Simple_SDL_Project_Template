#pragma once
#include <SDL_events.h>
#include <iostream>

#include "EventHandler.h"

class Event
{
public:
    Event()
    {
        EventHandler::registerEvent(this);
    }

    ~Event()
    {
        EventHandler::unregisterEvent(this);
    }

    virtual void onEvent(SDL_Event* event) {}
};