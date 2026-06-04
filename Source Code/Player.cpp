#include "Player.hpp"
#include "Constants.hpp"

Player::Player(const sf::Texture& texture)
    : sprite(texture)
{
    sprite.setScale({0.25f, 0.25f});
    reset();
}

void Player::reset()
{
    sprite.setPosition({80.f, 320.f});
}

void Player::update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        sprite.move({-Constants::PlayerSpeed, 0.f});

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        sprite.move({Constants::PlayerSpeed, 0.f});

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        sprite.move({0.f, -Constants::PlayerSpeed});

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        sprite.move({0.f, Constants::PlayerSpeed});

    keepInsideWindow();
}

void Player::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

sf::Vector2f Player::getBulletStartPosition() const
{
    auto bounds = sprite.getGlobalBounds();

    return {
        sprite.getPosition().x + bounds.size.x,
        sprite.getPosition().y + bounds.size.y / 2.f - 5.f
    };
}

sf::FloatRect Player::getBounds() const
{
    return sprite.getGlobalBounds();
}

void Player::keepInsideWindow()
{
    auto bounds = sprite.getGlobalBounds();
    auto position = sprite.getPosition();

    if(bounds.position.x < 0.f)
        sprite.setPosition({0.f, position.y});
    else if(bounds.position.x + bounds.size.x > Constants::WindowWidth)
        sprite.setPosition({Constants::WindowWidth - bounds.size.x, position.y});

    bounds = sprite.getGlobalBounds();
    position = sprite.getPosition();

    if(bounds.position.y < 0.f)
        sprite.setPosition({position.x, 0.f});
    else if(bounds.position.y + bounds.size.y > Constants::WindowHeight)
        sprite.setPosition({position.x, Constants::WindowHeight - bounds.size.y});
}
