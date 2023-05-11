#ifndef MISSILE_H
#define MISSILE_H

#include <GL/gl.h>
#include <iostream>
#include "sprite.h"
#include "collidable.h"
#include "entities.h"
#include "utils.h"


class Missile : public Sprite, Collidable
{
    public:
        float vel = 0.5f;
        Missile();
        virtual ~Missile();

        // Sprite
        void draw();
        void update(float deltaTime);

        //
        void onCollide(ENTITIES entity);

};

#endif // MISSILE_H
