#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

class Component {
private:
    static int ID_COUNTER;
    int uid;

public:
    Component();

    virtual void start();

    virtual void update(float dt);

    void generateId();

    int getUid() const;

    static void init(int maxId);
};

#endif // COMPONENT_H
