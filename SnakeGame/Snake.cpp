//
// Created by denis on 31.07.19.
//

#include "Snake.hpp"

#include <iostream>

Snake::Snake(const char *file_snake, float x, float y) : Shape("images/red.png", x, y, size, size){
    if(!texture.loadFromFile(file_snake)){
        std::cout << "File " << file_snake << " can not be opened" << std::endl;
        return;
    }
    sprite.setTexture(texture);
    for(int i = 0; i < num_sprites_in_snake; ++i){
        coord_sprietes.emplace_back(sf::Vector2f(x, y + i * size));
    }
}

void Snake::Move(){

    if(current_dir == STOP_SIGNAL)
        return;

    for(int i = num_sprites_in_snake - 1; i > 0; --i){
        coord_sprietes[i].x = coord_sprietes[i - 1].x;
        coord_sprietes[i].y = coord_sprietes[i - 1].y;
    }

    switch(current_dir) {
        case UP :
            coord_sprietes[0].y -= size;
            break;
        case DOWN :
            coord_sprietes[0].y += size;
            break;
        case LEFT :
            coord_sprietes[0].x -= size;
            break;
        case RIGHT :
            coord_sprietes[0].x += size;
            break;
    }
    Check_Limit();
    Check_Self_Intersection();
}

void Snake::Check_Limit(){
    if(coord_sprietes[0].x <= LEFT_WALL || coord_sprietes[0].y <= UP_WALL ||
       coord_sprietes[0].y >= DOWN_WALL || coord_sprietes[0].x >= RIGHT_WALL){
        ReturnToStartPosition();
    }

}

void Snake::ReturnToStartPosition(){
    coord_sprietes.resize(BEGIN_NUM_OF_SPRITES_SNAKE);
    num_sprites_in_snake = BEGIN_NUM_OF_SPRITES_SNAKE;
    coord_sprietes[0].x = x_ = 320;
    coord_sprietes[0].y = y_ = 320;
    current_dir = previous_dir = STOP_SIGNAL;
    for(int i = 1; i < num_sprites_in_snake; ++i){
        coord_sprietes[i] = sf::Vector2f(320, 320 + i * size);
    }
}

void Snake::Check_Self_Intersection(){
    for(int i = 2; i < num_sprites_in_snake; ++i){
        if(coord_sprietes[0].y == coord_sprietes[i].y && ((coord_sprietes[0].x + size == coord_sprietes[i].x) ||
                coord_sprietes[0].x - size == coord_sprietes[i].x))
        {
            ReturnToStartPosition();
            return;
        }
        else if(coord_sprietes[0].x == coord_sprietes[i].x && ((coord_sprietes[0].y + size == coord_sprietes[i].y) ||
        coord_sprietes[0].y - size == coord_sprietes[i].y)){
            ReturnToStartPosition();
            return;
        }
    }

}

void Snake::MakeDirectionMove(sf::Keyboard::Key key) {

    CHECK_POSSOBILITY_OF_TURN

    ACTION_WITH_KEYBOARD(current_dir)
}

void Snake::MarkTheLatestDir(sf::Keyboard::Key key) {

    CHECK_POSSOBILITY_OF_TURN

    ACTION_WITH_KEYBOARD(previous_dir)
}


void Snake::draw_snake(sf::RenderWindow& window){
    x_ = coord_sprietes[0].x;
    y_ = coord_sprietes[0].y;
    draw(window);
    for(int j = 1; j < num_sprites_in_snake; ++j){
        sprite.setPosition(coord_sprietes[j]);
        window.draw(sprite);
    }
}

float Snake::GetY_() const {
    return coord_sprietes[0].y;
}

float Snake::GetX_() const {
    return coord_sprietes[0].x;
}

void Snake::AddSprite() {
    coord_sprietes.emplace_back(sf::Vector2f(WRONG_COORDINATES, WRONG_COORDINATES));
    ++num_sprites_in_snake;
}

