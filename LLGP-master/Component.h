#pragma once
#include "Object.h"
class GameObject;
class Component :
    public Object
{
public:
    Component(GameObject* owner) : _GameObject(owner) {}
    virtual ~Component() {}

    GameObject* GetGameObjects() { return _GameObject; }

    virtual void OnwerActiveChange(bool newActive) {}
protected:
    GameObject* _GameObject;
};

