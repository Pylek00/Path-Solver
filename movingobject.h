#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "object.h"

class MovingObject : public Object
{
public:
    MovingObject();
    virtual ~MovingObject();

    //virtual void move(sf::RenderTarget* target) = 0;

protected:
    int speed;
};

#endif // MOVINGOBJECT_H
