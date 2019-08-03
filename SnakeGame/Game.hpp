//
// Created by denis on 31.07.19.
//

#pragma once
#include "Snake.hpp"
#include "Fruit.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>

#define STOP_SIGNAL -230

extern const int num_height;
extern const int num_width;
extern const int height;
extern const int width;


class Game {
public:
    Game(const char *file_map);

    void run();

private:
    void process_events();

    void update();

    void render();

    void CheckCollisionWithFruit();

    sf::RenderWindow window;
    sf::Sprite sprite_map;
    sf::Texture texture_map;
    sf::Image map;
    Snake snake;
    Fruit fruit;

};
