#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
    explicit Player(const sf::Texture& texture);

    void reset();
    void update();
    void draw(sf::RenderWindow& window) const;

    sf::Vector2f getBulletStartPosition() const;
    sf::FloatRect getBounds() const;

private:
    void keepInsideWindow();

    sf::Sprite sprite;
};
