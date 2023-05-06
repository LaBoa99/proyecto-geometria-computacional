#include "../include/player.h"
#include <iostream>
#include <GL/gl.h>
#include <math.h>

Player::Player() : Sprite(){
    Sprite::pos[0] = 0.1f;
    Sprite::pos[1] = 0.5f;
}

void Player::draw(){
    this->drawPlayer();
}

void Player::update(float deltaTime) {
    // GRAVEDAD
    if(this->isJumping){
        if(Sprite::pos[1] + this->SIZE <= 1.0f){
            Sprite::pos[1] += (this->JUMP_VEL + accJ) * deltaTime / 15;
            if(this->accJ < 0)
                this->accJ += abs(this->JUMP_VEL) * deltaTime;
        this->acc = -(this->JUMP_VEL / 2);
        }
    }

    if(Sprite::pos[1] > 0){
        Sprite::pos[1] += (GRAVITY - acc) * deltaTime / 15;
        if(this->isFalling){
            this->accJ = -(abs(this->GRAVITY) * 2);
        }
        if(this->acc < 0)
            this->acc += abs(this->GRAVITY) * deltaTime;
    }
}

void Player::jump(){
    this->isJumping = true;
    this->isFalling = false;
}

void Player::fall(){
    this->isJumping = false;
    this->isFalling = true;
}

void Player::drawPlayer(){
    if(Sprite::isVisible){
        glColor3f(0.0f, 0.5f, -1.0f);
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
