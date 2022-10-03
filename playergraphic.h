#ifndef PLAYERGRAPHIC_H
#define PLAYERGRAPHIC_H

#include "graphicobject.h"
#include "player.h"

class PlayerGraphic : public GraphicObject
{
public:
    PlayerGraphic(Player *player);
    virtual ~PlayerGraphic();


    //void draw(sf::RenderTarget* target);
    void update_render(Player* player, sf::RenderTarget* target);


private:

        sf::CircleShape shape;

};

#endif // PLAYERGRAPHIC_H
