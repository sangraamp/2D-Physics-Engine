#include "Component.h"

int Component::ID_COUNTER = 0;

Component::Component() : uid(-1) {}

void Component::start() {}

void Component::update(float dt) {}

void Component::generateId() {
    if (uid == -1) {
        uid = ID_COUNTER++;
    }
}

int Component::getUid() const {
    return uid;
}

void Component::init(int maxId) {
    ID_COUNTER = maxId;
}