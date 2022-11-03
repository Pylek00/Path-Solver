#ifndef PARTICLES_H
#define PARTICLES_H

#include "player.h"
#include "graphicobject.h"
#include <math.h>



class Particles : public GraphicObject
{
private:

    sf::CircleShape shape;
    float size;
    float velocity;
    float duration;
    float distance;
    float part_direction;
    int part_ammount;
    sf::Vector2f position;



public:
    Particles(sf::Vector2f position);
    virtual ~Particles();

    void update_render(Player* player, sf::RenderTarget* target);
};

#endif // PARTICLES_H
