#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "../primitives/Collider2D.h"
#include "../primitives/Circle.h"
#include "CollisionManifold.h"

class Collisions {
public:
    static CollisionManifold* findCollisionFeatures(Collider2D* c1, Collider2D* c2);
    static CollisionManifold* findCollisionFeatures(Circle* a, Circle* b);
};

#endif // COLLISIONS_H
