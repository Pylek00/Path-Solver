#ifndef OBJECT_H
#define OBJECT_H

#include "state.h"

class Object
{
public:
    //constructor/destructor
    Object();
    virtual ~Object();


    //functions

    //logic

    //getters
    virtual sf::Vector2f getPosition() = 0;
    virtual int getSize() =0;

    //setters
    virtual void setPosition(sf::Vector2f position) = 0;
    virtual void setSize(int size) = 0;


protected:
    //logic
    sf::Vector2f position;
    float size;
    bool visible;


private:

};

#endif // OBJECT_H
