#include "Bullet.hpp"
#include "Constants.hpp"

Bullet::Bullet(sf::Vector2f position)
{
    shape.setRadius(5.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position);
}

void Bullet::update()
{
    if(active)
        shape.move({Constants::BulletSpeed, 0.f});
}

void Bullet::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

bool Bullet::isActive() const
{
    return active;
}

void Bullet::deactivate()
{
    active = false;
}

bool Bullet::isOffscreen() const
{
    return shape.getPosition().x > Constants::WindowWidth + 20.f;
}

sf::FloatRect Bullet::getBounds() const
{
    return shape.getGlobalBounds();
}
