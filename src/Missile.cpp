#include "Missile.h"

Missile::Missile() : Sprite(), Collidable(this) {
    Sprite::w = 0.2f;
    Sprite::h = 0.05;
    Sprite::setPosition(1.0f + Sprite::w, Utils::genRandomFloat());
    Sprite::ID = MISSILE;
}

Missile::~Missile(){
    //dtor
}

void Missile::draw(){
    if(Sprite::isVisible){
        glColor3f(0.3f, 1.0f, 0.5f);
        glBegin(GL_POLYGON);
            glVertex2f(Sprite::pos[0], Sprite::pos[1] + Sprite::h / 2);
            glVertex2f(Sprite::pos[0] + Sprite::w / 3, Sprite::pos[1] + Sprite::h);
            glVertex2f(Sprite::pos[0] + ((Sprite::w / 3) * 2), Sprite::pos[1] + Sprite::h);
            glVertex2f(Sprite::pos[0] + ((Sprite::w / 3) * 2), Sprite::pos[1]);
            glVertex2f(Sprite::pos[0] + Sprite::w / 3, Sprite::pos[1]);
        glEnd();
    }
}

void Missile::update(float deltaTime){
    Sprite::pos[0] -= this->vel * deltaTime;

    if(Sprite::isActive){
        bool isOverpasedToLeft = Sprite::pos[0] < -Sprite::w ;
        Sprite::isVisible = isOverpasedToLeft || Sprite::pos[0] < (1 + Sprite::w);
        Sprite::isDestructible = isOverpasedToLeft;
    }
}

void Missile::onCollide(ENTITIES entity){
}
