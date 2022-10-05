#include "map.h"

#define MAP_SIZE_X   40
#define MAP_SIZE_Y   30


Map::Map(sf::RenderWindow* window)
{
    this->gameWindow = window;
    this->mapsize = sf::Vector2i(MAP_SIZE_X,MAP_SIZE_Y);
    this->createMap();
}
Map::~Map()
{
    for(int i=0;i < map_field.size();i++)
    {
        delete this->map_field[i];
    }

    this->map_field.clear();
}


void Map::createMap()
{
    for(int i=0;i < this->mapsize.x;i++)
    {
        for(int j=0; j<this->mapsize.y;j++)
        {
            this->map_field.push_back(new MapField(sf::Vector2f(5+i*25,5+j*25)));
        }
    }
}
void Map::update_renderMap()
{
    for(int i=0;i<this->map_field.size();i++)
    {
        this->map_field[i]->update_render(this->gameWindow);
    }

}
