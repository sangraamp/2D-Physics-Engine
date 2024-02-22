#include <SFML/Graphics.hpp>
#include "../physicssystem/PhysicsSystem2D.h"
#include "../primitives/Circle.h"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simple Physics Simulation");

    float dt = 0.016f; // 60 FPS

    // Create your physics system
    PhysicsSystem2D physicsSystem(dt, ::Vector2f(0.0f, 0.0981f)); // Assuming 60 FPS and Earth gravity

    // Add rigid bodies (squares)
    Rigidbody2D* rb1 = new Rigidbody2D();
    rb1->setMass(5);
    rb1->setTransform(::Vector2f(100, 0));
    Rigidbody2D* rb2 = new Rigidbody2D();
    rb2->setMass(10);
    rb2->setTransform(::Vector2f(100, 200));

    // Add circles
    Circle* c1 = new Circle();
    c1->setRadius(10.0f);
    c1->setRigidbody(rb1);
    Circle* c2 = new Circle();
    c2->setRadius(20.0f);
    c2->setRigidbody(rb2);
    rb1->setCollider(c1);
    rb2->setCollider(c2);

    // Add squares to the physics system
    physicsSystem.addRigidbody(rb1, true);
    physicsSystem.addRigidbody(rb2, false);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update physics system
        physicsSystem.update(dt);

        // Clear the window
        window.clear();

        // Draw squares
        // Assuming square1 and square2 have methods to get position and size
        sf::CircleShape shape1(10.0f);
        shape1.setFillColor(sf::Color::Red);
        shape1.setPosition(rb1->getPosition().getX(), rb1->getPosition().getY());
        // std::cout << "Window: " << square1->getPosition() << " " << square2->getPosition() << "\n";
        sf::CircleShape shape2(20.0f);
        shape2.setFillColor(sf::Color::Green);
        shape2.setPosition(rb2->getPosition().getX(), rb2->getPosition().getY());
        window.draw(shape1);
        window.draw(shape2);

        // Display content
        window.display();
    }

    return 0;
}
