#include "player.h"
#include <GL/gl.h>

Player::Player() : Sprite(){
    Sprite::pos[0] = 0.1f;
    Sprite::pos[1] = 0.5f;
}

void Player::draw(){
    this->drawPlayer();
}

void Player::update(float deltaTime) {
    // Solo cae cuando no estes en el suelo
    if (!isJumping && Sprite::pos[1] > 0) {
        Sprite::pos[1] -= GRAVITY * deltaTime / 15;
    // Solo salta cuando se de la indicacion y no choques con el techo
    } else if (Sprite::pos[1] + SIZE < 1 && (Sprite::pos[1] >= 0 || isJumping)) {
        Sprite::pos[1] += JUMP_VEL * deltaTime;
    }
}

void Player::jump(){
    this->isJumping = true;
}

void Player::fall(){
    this->isJumping = false;
}

void Player::drawPlayer(){
    if(Sprite::isVisible){
        glColor3f(0.0f, 0.5f, 1.0f);
        glBegin(GL_QUADS);
            glVertex2f(Sprite::pos[0], Sprite::pos[1]);
            glVertex2f(Sprite::pos[0], Sprite::pos[1] + this->SIZE);
            glVertex2f(Sprite::pos[0] + this->SIZE, Sprite::pos[1] + this->SIZE);
            glVertex2f(Sprite::pos[0] + this->SIZE, Sprite::pos[1]);
        glEnd();
    }
}

Player::~Player()
{
    //dtor
}
