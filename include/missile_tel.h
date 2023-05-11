#ifndef MISSILE_TEL_H
#define MISSILE_TEL_H

#include "Missile.h"
#include <iostream>
#include "player.h"

class Missile_tel : public Missile{
    public:
        Player* p;
        Missile_tel(Player* p) {
            this->p = p;
            this->vel = 0.3f;
        }
        virtual ~Missile_tel() {
            this->p = nullptr;
        }

        void update(float deltaTime) override{
            if(Sprite::pos[0] > 0.5f){
                if(Sprite::pos[1] >=  this->p->pos[1]){
                    Sprite::pos[1] -= this->vel * deltaTime;
                } else {
                    Sprite::pos[1] += this->vel * deltaTime;
                }
            } else {
                this->vel = 0.8f;
            }

            Sprite::pos[0] -= this->vel * deltaTime;



            if(Sprite::isActive){
                bool isOverpasedToLeft = Sprite::pos[0] < -Sprite::w ;
                Sprite::isVisible = isOverpasedToLeft || Sprite::pos[0] < (1 + Sprite::w);
                Sprite::isDestructible = isOverpasedToLeft;
            }
        }


    protected:

    private:
};

#endif // MISSILE_TEL_H
