#ifndef COLLISION_H
#define COLLISION_H

#include<SFML/Graphics.hpp>

class Collision
{
public:
    Collision(sf::RectangleShape& body);
    virtual ~Collision();




    bool ChceckCollision(Collision& other, float push);
    sf::Vector2f getPosition() {return body.getPosition();}
    sf::Vector2f getHalfSize() {return body.getSize()/2.0f;}



private:
    sf::RectangleShape& body;
};

#endif // COLLISION_H
