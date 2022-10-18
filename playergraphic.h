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
    void update_render(Player* player, sf::RenderTarget* target,sf::Shader* shader);


private:

        sf::CircleShape shape;
        sf::CircleShape lightShape;

};

#endif // PLAYERGRAPHIC_H
