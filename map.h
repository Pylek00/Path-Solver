#ifndef MAP_H
#define MAP_H

#define MAP_SIZE_X   40
#define MAP_SIZE_Y   30

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

    std::vector<MapField*> createMap();
    void update_renderMap();



};

#endif // MAP_H
