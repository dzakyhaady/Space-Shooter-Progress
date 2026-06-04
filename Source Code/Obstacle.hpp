#pragma once

#include <SFML/Graphics.hpp>

class Obstacle
{
public:
    Obstacle(const sf::Texture& texture, float y);

    void update();
    void draw(sf::RenderWindow& window) const;

    bool isActive() const;
    void deactivate();
    bool isOffscreen() const;
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;

private:
    sf::Sprite sprite;
    bool active = true;
};
