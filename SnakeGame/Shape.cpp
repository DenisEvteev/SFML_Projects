//
// Created by denis on 02.08.19.
//

#include "Shape.hpp"
#include <iostream>

Shape::Shape(const char* way_to_image, float x, float y, float w, float h) : x_(x), y_(y), w(w), h(h) {
    if(!image_.loadFromFile(way_to_image)){
        std::cout << "Can not open file : " << way_to_image << std::endl;
        return;
    }
    image_.createMaskFromColor(sf::Color(219, 218, 218));
    texture_.loadFromImage(image_);
    sprite_.setTexture(texture_);
}


void Shape::draw(sf::RenderWindow &window) {
    sprite_.setPosition(x_, y_);
    window.draw(sprite_);
}


float Shape::GetH() const {
    return h;
}

float Shape::GetW() const {
    return w;
}

float Shape::GetX_() const {
    return x_;
}

float Shape::GetY_() const {
    return y_;
}