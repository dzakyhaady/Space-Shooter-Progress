#include "Explosion.hpp"

Explosion::Explosion(sf::Vector2f position)
{
    shape.setRadius(15.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}

void Explosion::update()
{
    shape.scale({1.05f, 1.05f});
    timer--;
}

void Explosion::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

bool Explosion::isFinished() const
{
    return timer <= 0;
}
