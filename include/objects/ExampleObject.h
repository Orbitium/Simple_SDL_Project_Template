#pragma once

#include "root/GameObject.h"
#include "include/objects/addon/Texture.h"

class ExampleObject : public GameObject, Texture {
public:
    ExampleObject(ObjectManager *manager, const char* texturePath, int x, int y, int w, int h) 
    : GameObject(manager) , Texture(texturePath, x, y, w, h) {}

    void onNudge() override {
        destRect.x++;
        render();
    }
};