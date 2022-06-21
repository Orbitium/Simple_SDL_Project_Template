#pragma once
#include <SDL.h>
#include "../../GameWindow.h"
#include "../../Renderer.h"

class ObjectManager;

class GameObject
{
public:
	GameObject(ObjectManager* manager) { //Basic object
		this->manager = manager;
	}

	virtual void onNudge() {
		//override this function and call addon functions here
	}

private:
	ObjectManager* manager;
};