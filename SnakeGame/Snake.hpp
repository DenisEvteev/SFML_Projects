//
// Created by denis on 31.07.19.
//

#pragma once

#define STOP_SIGNAL -230
#define SPEED 0.1f
#define LEFT 2
#define RIGHT 3
#define UP 1
#define DOWN 0
#define LEFT_WALL 25
#define UP_WALL 22
#define DOWN_WALL 608
#define RIGHT_WALL 608
#define BEGIN_NUM_OF_SPRITES_SNAKE 4
#define WRONG_COORDINATES 10000


#include <SFML/Graphics.hpp>
#include "Shape.hpp"

#include <vector>


#define ACTION_WITH_KEYBOARD(x) if(key == sf::Keyboard::Right || key == sf::Keyboard::D)\
    x = RIGHT;\
else if(key == sf::Keyboard::Left || key == sf::Keyboard::A)\
    x = LEFT;\
else if(key == sf::Keyboard::Up || key == sf::Keyboard::W)\
    x = UP;\
else if(key == sf::Keyboard::Down || key == sf::Keyboard::S)\
    x = DOWN;\


#define CHECK_POSSOBILITY_OF_TURN if((key == sf::Keyboard::Right || key == sf::Keyboard::D) && previous_dir == LEFT)\
return;\
else if((key == sf::Keyboard::Left || key == sf::Keyboard::A) && previous_dir == RIGHT )\
return;\
else if((key == sf::Keyboard::Up || key == sf::Keyboard::W) && previous_dir == DOWN)\
return;\
else if((key == sf::Keyboard::Down || key == sf::Keyboard::S) && previous_dir == UP)\
return;\



extern const float size;

class Snake : Shape {
public:
    Snake(const char* file_snake, float x, float y);
    void MakeDirectionMove(sf::Keyboard::Key key);
    void MarkTheLatestDir(sf::Keyboard::Key key);

    void Move();

    void Check_Limit();
    void Check_Self_Intersection();
    void ReturnToStartPosition();

    void draw_snake(sf::RenderWindow& window);

    float GetX_()const;
    float GetY_()const;

    void AddSprite();

    sf::Sprite sprite;

private:
    int current_dir = STOP_SIGNAL;     // 0 - down, 1 - up, 2 - left, 3 - right
    int previous_dir = STOP_SIGNAL;    // 0 - down, 1 - up, 2 - left, 3 - right
    int num_sprites_in_snake = BEGIN_NUM_OF_SPRITES_SNAKE;
    sf::Texture texture;
    std::vector<sf::Vector2f> coord_sprietes;   // this vector contains coordinates of all the sprites of snake
};


