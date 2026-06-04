#pragma once

#include <SFML/Graphics.hpp>

class Background
{
public:
    explicit Background(const sf::Texture& texture);

    void draw(sf::RenderWindow& window) const;

private:
    sf::Sprite sprite;
};
