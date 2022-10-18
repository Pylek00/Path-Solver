#ifndef PLAYER_H
#define PLAYER_H

#include "movingobject.h"

class Player : public MovingObject
{
public:
    Player(int speed, int size);
    virtual ~Player();

    enum movement_direction{
        N=0 ,NE ,E ,SE, S, SW, W, NW
    };


    //getters
    sf::Vector2f getPosition();
    int getSize();
    int getSeeRange();
    float getRotation();

    //setters
    void setPosition(sf::Vector2f position);
    void setSize(int size);
    void setSpeed(int speed);
    void move(sf::RenderTarget* target);


private:
    sf::Vector2u mapSize;
    int seeRange;
    float rotation;
    bool direction[4];
protected:
};

#endif // PLAYER_H
