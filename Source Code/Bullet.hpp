#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
    explicit Bullet(sf::Vector2f position);

    void update();
    void draw(sf::RenderWindow& window) const;

    bool isActive() const;
    void deactivate();
    bool isOffscreen() const;
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
    bool active = true;
};
