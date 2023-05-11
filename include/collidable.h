#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "sprite.h"
// Solo funciona con rectangulos
class Collidable {
    public:
        Sprite* local;

        Collidable(Sprite* local) {
            this->local = local;
        }
        virtual ~Collidable() {

        }
        // Se pasa el punto inferior izquierdo
        bool collide(Sprite* obj){
            // Rectángulo de colisión del objeto colisionador
            float obj_left = obj->pos[0];
            float obj_right = obj->pos[0] + obj->w;
            float obj_top = obj->pos[1] + obj->h;
            float obj_bottom = obj->pos[1];

            // Rectángulo de colisión del sprite
            float spr_left = this->local->pos[0];
            float spr_right = this->local->pos[0] + this->local->w;
            float spr_top = this->local->pos[1] + this->local->h;
            float spr_bottom = this->local->pos[1];

            // Comprueba si los rectángulos se solapan
            bool isCollide = (spr_left <= obj_right) && (spr_right >= obj_left) && (spr_bottom <= obj_top) && (spr_top >= obj_bottom);

            // Si hay colisión, llama a la función onCollide del sprite
            if(isCollide){
                this->onCollide(obj->ID);
            }

            return isCollide;
        }


        virtual void onCollide(ENTITIES entity) = 0;

};

#endif // COLLIDABLE_H
