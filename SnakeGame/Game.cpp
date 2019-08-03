//
// Created by denis on 31.07.19.
//

#include "Game.hpp"


const float size = 16;
const int num_height = 40;
const int num_width = 40;
const int height = size * num_height;
const int width = size * num_width;


Game::Game(const char* file_map) : window(sf::VideoMode(width, height), "Everybody wants 3802!"),
snake("images/green.png", width / 2, height / 2), fruit(5 * size, 5 * size){
    if(!map.loadFromFile(file_map)){
        std::cout << "Can not open file with map" << file_map << std::endl;
        return;
    }
    texture_map.loadFromImage(map);
    sprite_map.setTexture(texture_map);
}


void Game::process_events() {
    sf::Event event;


    while(window.pollEvent(event)){


        switch(event.type){
            case sf::Event::KeyPressed : {
                snake.MakeDirectionMove(event.key.code);
                break;
            }

            case sf::Event::KeyReleased : {
                snake.MarkTheLatestDir(event.key.code);
                break;
            }

            case sf::Event::Closed :
                window.close();

        }
    }
}

void Game::run() {

    sf::Clock clock;

    sf::Time time_meas = sf::Time::Zero;

    float time{0};
    float period_update = SPEED;


    while(window.isOpen()){

        time_meas = clock.restart();
        time += time_meas.asSeconds();

        process_events();

        if(time > period_update){
            time = 0;
            update();
        }

        render();
    }
}

void Game::update(){
    snake.Move();
    CheckCollisionWithFruit();
}

void Game::render() {

    window.clear();


    window.draw(sprite_map);

    fruit.draw_fruit(window);


    /*for(int i = 0; i < num_width; ++i){
        for(int j = 0; j < num_height; ++j){
            sprite_map.setPosition(i * size, j * size);
            window.draw(sprite_map);
        }
    }*/

    snake.draw_snake(window);

    window.display();

}

void Game::CheckCollisionWithFruit() {
    if((snake.GetX_() <= fruit.GetX_() + fruit.GetW() && snake.GetX_() >= fruit.GetX_()) &&
    (snake.GetY_() >= fruit.GetY_() && snake.GetY_() <= fruit.GetY_() + fruit.GetH())){
        fruit.generate_fruit();
        snake.AddSprite();
    }
}