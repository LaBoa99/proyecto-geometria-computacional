#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include "collidable.h"


class Player : public Sprite, public Collidable
{
    public:
        bool isJumping = false;
        bool isFalling = true;
        bool isAlive = true;
        float vel, acc = 0, accJ = 0;

        Player();
        virtual ~Player();
        void jump();
        void fall();
        void death();


        // Sprite
        void update(float deltaTime) override;
        void draw() override;
        // Collision
        void onCollide(ENTITIES entity) override;

    private:
        void drawPlayer();

        const float SIZE = 0.10f;
        const float GRAVITY = -9.8f;
        const float JUMP_VEL = 30.0f;

};

#endif // PLAYER_H
