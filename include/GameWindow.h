#pragma once
#include "include/events/Event.h"

class SDL_Window;

class GameWindow : public Event
{
public:
	GameWindow() : Event() {}

	bool init(const char* title, int x, int y, int width, int height, bool fullscreen);

	void onEvent(SDL_Event* event) override {
		if (event->type == SDL_QUIT)
			isRunning = 0;
	}

	bool isRunning;
private:
	SDL_Window* window;
};
