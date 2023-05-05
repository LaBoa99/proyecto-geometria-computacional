#ifndef SPRITE_H
#define SPRITE_H


class Sprite {
    public:
    float pos[2];
    bool isVisible = true;
    bool isDestructible = false;

    Sprite() {
        this->pos[0] = 0.0f;
        this->pos[1] = 0.0f;
    }
    virtual ~Sprite() {
    }

    void setPosition(float x, float y) {
        this->pos[0] = x;
        this->pos[1] = y;
    }

    float* getPosition(){
        float* pos = new float[2];
        pos[0] = this->pos[0];
        pos[1] = this->pos[1];
        return pos;
    }

    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;
};

#endif // SPRITE_H
