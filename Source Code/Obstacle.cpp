#include "Obstacle.hpp"
#include "Constants.hpp"

Obstacle::Obstacle(const sf::Texture& texture, float y)
    : sprite(texture)
{
    sprite.setScale({0.17f, 0.17f});
    sprite.setPosition({Constants::WindowWidth + 100.f, y});
}

void Obstacle::update()
{
    if(active)
        sprite.move({-Constants::ObstacleSpeed, 0.f});
}

void Obstacle::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

bool Obstacle::isActive() const
{
    return active;
}

void Obstacle::deactivate()
{
    active = false;
}

bool Obstacle::isOffscreen() const
{
    return sprite.getPosition().x < -150.f;
}

sf::FloatRect Obstacle::getBounds() const
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Obstacle::getPosition() const
{
    return sprite.getPosition();
}
