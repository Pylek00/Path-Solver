#include "map.h"




Map::Map(sf::RenderWindow* window)
{
    this->gameWindow = window;
    this->mapsize = sf::Vector2i(MAP_SIZE_X,MAP_SIZE_Y);

}
Map::~Map()
{
    for(int i=0;i < map_field.size();i++)
    {
        delete this->map_field[i];
    }

    this->map_field.clear();
}


std::vector<MapField *> Map::createMap()
{
    for(int i=0;i < this->mapsize.x;i++)
    {
        for(int j=0; j<this->mapsize.y;j++)
        {
            this->map_field.push_back(
                        new MapField(sf::Vector2f(
                                         5+i*(FIELD_SIZE+5)+FIELD_SIZE/2.0f,FIELD_SIZE/2.0f+5+j*(FIELD_SIZE+5)
                                         ),i,j));
        }
    }
    return this->map_field;
}
void Map::update_renderMap()
{
    for(int i=0;i<this->map_field.size();i++)
    {
        this->map_field[i]->update_render(this->gameWindow);
    }

}
