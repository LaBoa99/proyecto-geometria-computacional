#include "../include/wall.h"
#include "../include/utils.h"
#include "entities.h"
#include <GL/gl.h>

Wall::Wall() : Sprite(){
    this->height = Utils::genRandomFloat(0.2f, 0.7f);
    this->GAP_RECT = Utils::genRandomFloat(0.3f, 0.4f);
    this->gap_h = this->GAP_RECT + this->height;
    this->coin = new Coin();
    // esto se hace para que inicia de izquierda a derecha
    Sprite::pos[0] += 1 + this->WIDTH_RECT;
    Sprite::w = this->WIDTH_RECT;
    Sprite::h = this->height;
    Sprite::ID = WALL;
    this->coin->setPosition(Sprite::pos[0] + (Sprite::w / 2), Sprite::pos[1] + Sprite::h + this->gap_h / 4);
}

Wall::~Wall(){
    delete this->coin;
}

void Wall::update(float deltaTime){
    Sprite::pos[0] -= 0.1 * deltaTime;
    // update status
    bool isOverpasedToLeft = Sprite::pos[0] < -this->WIDTH_RECT ;
    Sprite::isVisible = isOverpasedToLeft || Sprite::pos[0] < (1 + this->WIDTH_RECT);
    Sprite::isDestructible = isOverpasedToLeft;
    this->coin->update(deltaTime);
}

void Wall::draw(){
    this->coin->draw();
    this->drawRect();
}

void Wall::drawRect(){
    if(Sprite::isVisible && Sprite::isActive){
        // Parte Inferior
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f(Sprite::pos[0], Sprite::pos[1]);
            glVertex2f(Sprite::pos[0], Sprite::pos[1] + this->height);
            glVertex2f(Sprite::pos[0] + this->WIDTH_RECT, Sprite::pos[1] + this->height);
            glVertex2f(Sprite::pos[0] + this->WIDTH_RECT, Sprite::pos[1]);
        glEnd();

        // Parte superior
        glBegin(GL_QUADS);
            glVertex2f(Sprite::pos[0], Sprite::pos[1] + this->gap_h);
            glVertex2f(Sprite::pos[0], Sprite::pos[1] + this->gap_h + (1 - this->height));
            glVertex2f(Sprite::pos[0] + this->WIDTH_RECT, Sprite::pos[1] + this->gap_h + (1 - this->height));
            glVertex2f(Sprite::pos[0] + this->WIDTH_RECT, Sprite::pos[1] + this->gap_h);
        glEnd();
    }
}
