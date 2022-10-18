#ifndef MAPFIELD_H
#define MAPFIELD_H

#define FIELD_SIZE 20

#include "graphicobject.h"

class MapField : public GraphicObject
{
public:

    MapField(sf::Vector2f position,int x,int y);
    virtual ~MapField();
    //logic
    void update_render(sf::RenderTarget* target);
    void makeVisited();
    void makeWall();
    //getters
    float getSize();
    sf::Vector2f getPosition();
    bool getVisited();
    bool getIfWall();
    //setters
    void setVisited();
    void setWall();

    int x,y;

    sf::RectangleShape shape;
protected:
    //sf::RectangleShape shape;
private:
    float size;
    sf::Vector2f position;
    bool visited;
    bool isWall;
};

#endif // MAPFIELD_H
