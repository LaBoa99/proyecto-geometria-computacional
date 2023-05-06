#ifndef WALL_H
#define WALL_H

#include "sprite.h"

class Wall : public Sprite
{
    public:
        Wall();
        virtual ~Wall();

        // Sprite
        void update(float deltaTime) override;
        void draw() override;

    private:
        void drawRect();
        float height = 0.0f;
        float gap_h;
        float GAP_RECT = 0.4;
        const float WIDTH_RECT = 0.1;
};

#endif // WALL_H
