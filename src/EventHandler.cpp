#include "include/events/EventHandler.h"
#include "include/GameWindow.h"
#include "include/events/Event.h"

std::unordered_set<Event*> EventHandler::handlers;

void EventHandler::handleEvents()
{
	SDL_PollEvent(&event);

    for (Event* eventHandler : handlers)
    {
        eventHandler->onEvent(&event);
	}
}

void EventHandler::registerEvent(Event* event)
{
    handlers.insert(event);
}

void EventHandler::unregisterEvent(Event* event)
{
    handlers.erase(event);
}