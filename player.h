#ifndef PLAYER_H
#define PLAYER_H

#include "movingobject.h"

class Player : public MovingObject
{
public:
    Player(int speed, int size);
    virtual ~Player();




    //getters
    sf::Vector2f getPosition();
    int getSize();

    //setters
    void setPosition(sf::Vector2f position);
    void setSize(int size);
    void setSpeed(int speed);
    void move(sf::RenderTarget* target);

private:
    sf::Vector2u mapSize;

protected:
};

#endif // PLAYER_H
