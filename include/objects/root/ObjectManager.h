#pragma once
#include <vector>
#include <unordered_set> 
#include <map>
#include <iostream>

class GameObject;

class ObjectManager
{
public:

    template<typename T, typename... TArgs> T* createObject(int priority, TArgs... args) {
        T* object = new T(this, args...);
        if (!objects.count(priority)) {
                std::unordered_set<GameObject*> layer;
                layer.insert(object);
                objects.insert({priority,layer});
            }
            else
                objects.at(priority).insert(object);
        return object;
    } //Create object and return object's pointer
    
    void deleteObject(int priority, GameObject* object); //Transfer object to deleteQueue and remove objects vector
    void nudgeObjects();
    void clearObjects(); //Delete objects(with delete keyword) on deleteQueue

private:
    std::map<int, std::unordered_set<GameObject*>> objects;
    std::vector<GameObject*> deleteQueue;
};