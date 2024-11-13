#include "ObjectManager.h"
#include "AmmoBox.h"
#include "HealthBox.h"
#include <iostream>

std::vector<Object*>* ObjectManager::getObjectList()
{
    std::vector<Object*>* ptr = &objectList;
    return ptr;
}

void ObjectManager::initObjects()
{
    FileReader::readObjectsFromFile("object_data.csv", objectList);
}

void ObjectManager::clearObjects()
{
    objectList.clear();
}

void ObjectManager::checkForPickup()
{
    double dist = 0;
    Object* ptr = 0;
    int counter = 0;
    for (auto& obj : objectList) {
        ptr = obj;
        dist = obj->sprite->getDistanceFromPlayer(obj->position, *Player::getInstance());
        if (dist < 0.5) {
			auto ammoPtr = dynamic_cast<AmmoBox*>(ptr);
			auto healthPtr = dynamic_cast<HealthBox*>(ptr);
            if (ammoPtr) {
                if (ammoPtr->pickup()) {
					delete ammoPtr->sprite;
					delete ammoPtr;
					objectList.erase(objectList.begin() + counter);
                }
            }
            else if (healthPtr) {
                if (healthPtr->pickup()) {
					delete healthPtr->sprite;
					delete healthPtr;
					objectList.erase(objectList.begin() + counter);
                }
            }
        }
        counter++;
    }
}
