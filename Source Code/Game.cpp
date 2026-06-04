#include "Game.hpp"
#include "Constants.hpp"

#include <algorithm>
#include <iostream>

Game::Game()
    : window(
          sf::VideoMode({
              static_cast<unsigned>(Constants::WindowWidth),
              static_cast<unsigned>(Constants::WindowHeight)
          }),
          "Space Shooter"
      ),
      scoreText(font),
      gameOverText(font),
      restartText(font),
      rng(std::random_device{}()),
      obstacleY(0.f, Constants::WindowHeight - 100.f)
{
    window.setFramerateLimit(60);
}

int Game::run()
{
    if(!loadResources())
        return -1;

    while(window.isOpen())
    {
        processEvents();
        update();
        render();
    }

    return 0;
}

bool Game::loadResources()
{
    if(!backgroundTexture.loadFromFile("assets/bgcc.png"))
    {
        std::cout << "Gagal load bgcc.png\n";
        return false;
    }

    if(!playerTexture.loadFromFile("assets/ship5.gif"))
    {
        std::cout << "Gagal load ship5.gif\n";
        return false;
    }

    if(!obstacleTexture.loadFromFile("assets/batu.gif"))
    {
        std::cout << "Gagal load batu.gif\n";
        return false;
    }

    if(music.openFromFile("assets/backsound.wav"))
    {
        music.setLooping(true);
        music.play();
    }

    if(!font.openFromFile("assets/arial.ttf") &&
       !font.openFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cout << "Font tidak ditemukan. Simpan arial.ttf di folder assets.\n";
        return false;
    }

    background = std::make_unique<Background>(backgroundTexture);
    player = std::make_unique<Player>(playerTexture);

    scoreText = sf::Text(font);
    scoreText.setCharacterSize(30);

    gameOverText = sf::Text(font);
    gameOverText.setCharacterSize(60);
    gameOverText.setString("GAME OVER");

    restartText = sf::Text(font);
    restartText.setCharacterSize(28);
    restartText.setString("Press R to Restart");

    return true;
}

void Game::processEvents()
{
    while(auto event = window.pollEvent())
    {
        if(event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update()
{
    if(gameOver &&
       sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) &&
       restartClock.getElapsedTime().asMilliseconds() > 250)
    {
        restart();
    }

    if(gameOver)
        return;

    player->update();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) &&
       shootClock.getElapsedTime().asMilliseconds() > Constants::ShootDelayMs)
    {
        shoot();
    }

    if(spawnClock.getElapsedTime().asSeconds() > Constants::SpawnDelaySeconds)
    {
        spawnObstacle();
    }

    for(auto& bullet : bullets)
        bullet.update();

    for(auto& obstacle : obstacles)
        obstacle.update();

    checkCollisions();

    for(auto& explosion : explosions)
        explosion.update();

    cleanObjects();
}

void Game::render()
{
    scoreText.setString("Score : " + std::to_string(score));
    scoreText.setPosition({20.f, 20.f});

    window.clear();

    background->draw(window);

    for(const auto& bullet : bullets)
        bullet.draw(window);

    for(const auto& obstacle : obstacles)
        obstacle.draw(window);

    for(const auto& explosion : explosions)
        explosion.draw(window);

    player->draw(window);
    window.draw(scoreText);

    if(gameOver)
    {
        gameOverText.setPosition({450.f, 300.f});
        restartText.setPosition({500.f, 380.f});

        window.draw(gameOverText);
        window.draw(restartText);
    }

    window.display();
}

void Game::shoot()
{
    bullets.emplace_back(player->getBulletStartPosition());
    shootClock.restart();
}

void Game::spawnObstacle()
{
    obstacles.emplace_back(obstacleTexture, obstacleY(rng));
    spawnClock.restart();
}

void Game::checkCollisions()
{
    for(auto& bullet : bullets)
    {
        if(!bullet.isActive())
            continue;

        for(auto& obstacle : obstacles)
        {
            if(!obstacle.isActive())
                continue;

            if(bullet.getBounds().findIntersection(obstacle.getBounds()).has_value())
            {
                bullet.deactivate();
                obstacle.deactivate();
                score += 10;
                explosions.emplace_back(obstacle.getPosition());
            }
        }
    }

    for(auto& obstacle : obstacles)
    {
        if(obstacle.isActive() &&
           player->getBounds().findIntersection(obstacle.getBounds()).has_value())
        {
            gameOver = true;
        }
    }
}

void Game::cleanObjects()
{
    bullets.erase(
        std::remove_if(
            bullets.begin(),
            bullets.end(),
            [](const Bullet& bullet)
            {
                return !bullet.isActive() || bullet.isOffscreen();
            }
        ),
        bullets.end()
    );

    obstacles.erase(
        std::remove_if(
            obstacles.begin(),
            obstacles.end(),
            [](const Obstacle& obstacle)
            {
                return !obstacle.isActive() || obstacle.isOffscreen();
            }
        ),
        obstacles.end()
    );

    explosions.erase(
        std::remove_if(
            explosions.begin(),
            explosions.end(),
            [](const Explosion& explosion)
            {
                return explosion.isFinished();
            }
        ),
        explosions.end()
    );
}

void Game::restart()
{
    bullets.clear();
    obstacles.clear();
    explosions.clear();
    score = 0;
    gameOver = false;
    player->reset();
    shootClock.restart();
    spawnClock.restart();
    restartClock.restart();
}
