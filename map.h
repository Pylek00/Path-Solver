#ifndef MAP_H
#define MAP_H

#include "mapfield.h"
//#include "mazewall.h"

class Map
{
public:
    Map(sf::RenderWindow* window);
    virtual ~Map();

    sf::Vector2i mapsize;
    sf::Vector2i objectSize;
    std::vector<MapField*> map_field;
    sf::RenderWindow* gameWindow;

    void createMap();
    void update_renderMap();



};

#endif // MAP_H
