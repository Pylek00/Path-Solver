#ifndef MAPFIELD_H
#define MAPFIELD_H

#include "graphicobject.h"

class MapField : public GraphicObject
{
public:

    MapField(sf::Vector2f position);
    virtual ~MapField();
    //logic
    void update_render(sf::RenderTarget* target);
    void makeVisited();
    //getters
    float getSize();
    sf::Vector2f getPosition();
    bool getVisited();
    //setters
    void setVisited();


protected:
    sf::RectangleShape shape;
private:
    float size;
    sf::Vector2f position;
    bool visited;
};

#endif // MAPFIELD_H
