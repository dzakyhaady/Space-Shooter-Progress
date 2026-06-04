#pragma once

#include "Background.hpp"
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <random>
#include <vector>

class Game
{
public:
    Game();

    int run();

private:
    bool loadResources();
    void processEvents();
    void update();
    void render();
    void shoot();
    void spawnObstacle();
    void checkCollisions();
    void cleanObjects();
    void restart();

    sf::RenderWindow window;

    sf::Texture backgroundTexture;
    sf::Texture playerTexture;
    sf::Texture obstacleTexture;
    sf::Font font;
    sf::Music music;

    std::unique_ptr<Background> background;
    std::unique_ptr<Player> player;

    std::vector<Bullet> bullets;
    std::vector<Obstacle> obstacles;
    std::vector<Explosion> explosions;

    sf::Text scoreText;
    sf::Text gameOverText;
    sf::Text restartText;

    sf::Clock shootClock;
    sf::Clock spawnClock;
    sf::Clock restartClock;

    std::mt19937 rng;
    std::uniform_real_distribution<float> obstacleY;

    int score = 0;
    bool gameOver = false;
};
