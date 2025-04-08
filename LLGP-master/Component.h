#pragma once
#include "Object.h"

namespace LLGP {
    class GameObject;

    class Component : public Object
    {
    public:
        Component() {}
        Component(GameObject* owner) : _GameObject(owner) {}
        virtual ~Component() {}

        GameObject* GetGameObjects() { return _GameObject; }

        virtual void OwnerActiveChange(bool newActive) {};

        virtual void OnwerActiveChange(bool newActive) {}
    protected:
        GameObject* _GameObject;
    };
}


