#ifndef PLAYER_H
#define PLAYER_H

#include <sprite.h>


class Player : public Sprite
{
    public:
        bool isJumping = false;
        bool isAlive = true;
        float vel, acc;

        Player();
        virtual ~Player();
        void jump();
        void fall();


        // Sprite
        void update(float deltaTime) override;
        void draw() override;

    private:
        void drawPlayer();

        const float SIZE = 0.10f;
        const float GRAVITY = 9.8f;
        const float JUMP_VEL = 0.9f;

};

#endif // PLAYER_H
