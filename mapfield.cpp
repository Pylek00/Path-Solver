#include "mapfield.h"





MapField::MapField(sf::Vector2f position,int x, int y)
{
    this->size = FIELD_SIZE;
    this->shape = sf::RectangleShape(sf::Vector2f(this->size,this->size));
    this->shape.setFillColor(sf::Color::Blue);
    this->visited = false;
    this->isWall = false;
    this->position = position;
    this->shape.setPosition(position);
    this->shape.setOrigin(this->size/2.0f,this->size/2.0f);
    this->x = x;
    this->y = y;

}
MapField::~MapField()
{

}

void MapField::update_render(sf::RenderTarget* target)
{
    //this->shape.setPosition(this->position);
    target->draw(this->shape);
}
float MapField::getSize()
{
    return this->size;
}
sf::Vector2f MapField::getPosition()
{
    return this->position;
}
//////////visiting
bool MapField::getVisited()
{
    return this->visited;
}
void MapField::setVisited()
{
    this->visited = true;
}
void MapField::makeVisited()
{

    if(!this->visited && !this->isWall)
    {
        this->shape.setFillColor(sf::Color::White);
        this->visited = true;
    }
}
///////////end visiting
//////////making wall
bool MapField::getIfWall()
{
    return this->isWall;
}
void MapField::setWall()
{
    this->isWall = true;
}
void MapField::makeWall()
{
    if(!this->isWall)
    {
        this->shape.setFillColor(sf::Color::Red);
        this->setWall();
    }
}
