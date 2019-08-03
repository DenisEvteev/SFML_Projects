//
// Created by denis on 02.08.19.
//

#include "Fruit.hpp"

Fruit::Fruit(float x, float y) : Shape("images/fruits.png", x, y, W_FRUIT, H_FRUIT) {}

void Fruit::generate_fruit() {
    ++count;
    if(count < NUM_FRUITS_IN_ONE_STRIP)
        sprite_.setTextureRect(sf::IntRect(count * W_FRUIT, 0, w, h));
    else
        sprite_.setTextureRect(sf::IntRect((count  - NUM_FRUITS_IN_ONE_STRIP) * W_FRUIT, H_FRUIT, w, h));
    if(count == 2 * NUM_FRUITS_IN_ONE_STRIP - 2)
        count = 0;

    x_ = rand() % 565 + 28;
    y_ = rand() % 565 + 25;

}

void Fruit::draw_fruit(sf::RenderWindow& window) {
    if(count == 0)
        sprite_.setTextureRect(sf::IntRect(0, 0, w, h));
    draw(window);
}