#ifndef COIN_H
#define COIN_H

#include <GL/gl.h>
#include <iostream>
#include "sprite.h"
#include "collidable.h"
#include "entities.h"

class Coin : public Sprite, Collidable
{
    public:
        Coin() : Sprite(), Collidable(this) {
            Sprite::h = 0.02;
            Sprite::w = 0.02;
            Sprite::ID = COIN;
        }
        virtual ~Coin() {}

        void update(float deltaTime) override {
            Sprite::pos[0] -= 0.1 * deltaTime;
            // update status
            bool isOverpasedToLeft = Sprite::pos[0] < -Sprite::w ;
            if(Sprite::isVisible == false){
                Sprite::isVisible = isOverpasedToLeft || Sprite::pos[0] < (1 + Sprite::w);
            }
            Sprite::isDestructible = isOverpasedToLeft;
        }

        void draw(){
            if(Sprite::isVisible && Sprite::isActive){
                glColor3f(0.93f, 0.79f, 0.16f);
                glBegin(GL_QUADS);
                    glVertex2f(Sprite::pos[0], Sprite::pos[1]);
                    glVertex2f(Sprite::pos[0], Sprite::pos[1] + Sprite::h);
                    glVertex2f(Sprite::pos[0] + Sprite::w, Sprite::pos[1] + Sprite::h);
                    glVertex2f(Sprite::pos[0] + Sprite::w, Sprite::pos[1]);
                glEnd();
            }
        }

        void onCollide(ENTITIES entity){
            if(Sprite::isActive){
                if(entity == PLAYER){
                    this->isVisible = false;
                    this->isActive = false;
                    this->isDestructible = true;
                }
            }
        }

};

#endif // COIN_H
