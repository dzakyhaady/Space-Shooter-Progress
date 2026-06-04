#pragma once

#include <SFML/Graphics.hpp>

class Explosion
{
public:
    explicit Explosion(sf::Vector2f position);

    void update();
    void draw(sf::RenderWindow& window) const;
    bool isFinished() const;

private:
    sf::CircleShape shape;
    int timer = 20;
};
