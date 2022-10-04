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
    int getSeeRange();

    //setters
    void setPosition(sf::Vector2f position);
    void setSize(int size);
    void setSpeed(int speed);
    void move(sf::RenderTarget* target);

private:
    sf::Vector2u mapSize;
    int seeRange;

protected:
};

#endif // PLAYER_H
