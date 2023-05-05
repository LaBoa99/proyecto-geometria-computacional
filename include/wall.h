#ifndef WALL_H
#define WALL_H

#include <sprite.h>

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
        const float WIDTH_RECT = 0.1;
        const float GAP_RECT = 0.2;
};

#endif // WALL_H
