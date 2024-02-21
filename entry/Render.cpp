#include <SFML/Graphics.hpp>
#include "../physicssystem/PhysicsSystem2D.h"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simple Physics Simulation");

    float dt = 0.016f; // 60 FPS

    // Create your physics system
    PhysicsSystem2D physicsSystem(dt, ::Vector2f(0.0f, 0.0981f)); // Assuming 60 FPS and Earth gravity

    // Add rigid bodies (squares)
    Rigidbody2D* square1 = new Rigidbody2D();
    square1->setMass(10);
    square1->setTransform(Vector2f(100, 0));
    Rigidbody2D* square2 = new Rigidbody2D();
    square2->setMass(5);
    square2->setTransform(Vector2f(100, 200));
    // Add squares to the physics system
    physicsSystem.addRigidbody(square1, true);
    physicsSystem.addRigidbody(square2, false);

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
        sf::RectangleShape shape1(sf::Vector2f(50, 50));
        shape1.setFillColor(sf::Color::Red);
        shape1.setPosition(square1->getPosition().getX(), square1->getPosition().getY());
        // std::cout << "Window: " << square1->getPosition() << " " << square2->getPosition() << "\n";
        sf::RectangleShape shape2(sf::Vector2f(50, 50));
        shape2.setFillColor(sf::Color::Green);
        shape2.setPosition(square2->getPosition().getX() + 100, square2->getPosition().getY());
        window.draw(shape1);
        window.draw(shape2);

        // Display content
        window.display();
    }

    return 0;
}
