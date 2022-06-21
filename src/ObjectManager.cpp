#include "include/objects/root/ObjectManager.h"
#include "include/objects/root/GameObject.h"


void ObjectManager::deleteObject(int priority, GameObject* object) {
    objects.at(priority).erase(object);
    deleteQueue.push_back(object);
}

void ObjectManager::nudgeObjects() {
    for (std::pair<int, std::unordered_set<GameObject*>> layer : objects) {
        for (GameObject* item : layer.second) {
            item->onNudge();
        }
    }
}

void ObjectManager::clearObjects() {
    for (GameObject* object : deleteQueue) {
        delete object;
    }
    deleteQueue.clear();
}