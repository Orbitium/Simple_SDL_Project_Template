#define SDL_MAIN_HANDLED

#include <SDL.h>

#include "include/GameWindow.h"
#include "include/objects/root/ObjectManager.h"
#include "include/Renderer.h"
#include "include/events/EventHandler.h"

#include "include/objects/ExampleObject.h"


int main(int argv, char** args) {
	EventHandler eventHandler;
	GameWindow gameWindow;
	Renderer renderer;
	ObjectManager objectManager;
	//Create objects below init, not here(renderer is not initialized yet)
	if (gameWindow.init("Window title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false)) {
		objectManager.createObject<ExampleObject>(0, "../res/box1.png", 0, 10, 50, 50);
		while (gameWindow.isRunning) {
			renderer.clear();
			eventHandler.handleEvents();
			objectManager.nudgeObjects();
			renderer.resetColor();
			renderer.draw();
			SDL_Delay(16);
		}
	}
	return 0;
}