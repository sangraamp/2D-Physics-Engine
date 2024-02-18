#include "RaycastResult.h"

RaycastResult::RaycastResult() {
    this->point = Vector2f();
    this->normal = Vector2f();
    this->t = -1;
    this->hit = false;
}

void RaycastResult::init(Vector2f point, Vector2f normal, float t, bool hit) {
    this->point = point;
    this->normal = normal;
    this->t = t;
    this->hit = hit;
}

void RaycastResult::reset(RaycastResult* result) {
    if(result != NULL) {
        result->point = Vector2f(0, 0);
        result->normal = Vector2f(0, 0);
        result->t = -1;
        result->hit = false;
    }
}
