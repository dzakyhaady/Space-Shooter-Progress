#include "Background.hpp"
#include "Constants.hpp"

Background::Background(const sf::Texture& texture)
    : sprite(texture)
{
    sprite.setScale({
        Constants::WindowWidth / texture.getSize().x,
        Constants::WindowHeight / texture.getSize().y
    });
}

void Background::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}
