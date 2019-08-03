//
// Created by denis on 02.08.19.
//

#pragma once

#include <SFML/Graphics.hpp>

class Shape {
public:
    Shape(const char* way_to_image, float x, float y, float w, float h);
    void draw(sf::RenderWindow &window);

    float GetX_()const;
    float GetY_()const;
    float GetW()const;
    float GetH()const;

protected:
    float x_, y_, w, h;
    sf::Image image_;
    sf::Texture texture_;
    sf::Sprite sprite_;


};

