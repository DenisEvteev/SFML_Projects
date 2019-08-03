//
// Created by denis on 02.08.19.
//
#pragma once
#include "Shape.hpp"

#define W_FRUIT 34
#define H_FRUIT 34
#define NUM_FRUITS_IN_ONE_STRIP 14


class Fruit : public Shape {
    int count = 0;

public:
    Fruit(float x, float y);
    void generate_fruit();
    void draw_fruit(sf::RenderWindow& window);
};


