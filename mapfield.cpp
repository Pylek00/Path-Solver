#include "mapfield.h"





MapField::MapField(sf::Vector2f position)
{
    this->size = 20.f;
    this->shape = sf::RectangleShape(sf::Vector2f(this->size,this->size));
    this->shape.setFillColor(sf::Color::Blue);
    this->visited = false;
    this->position = position;
    this->shape.setPosition(position);

}
MapField::~MapField()
{

}
void MapField::makeVisited()
{

    if(!this->visited)
    {
        this->shape.setFillColor(sf::Color::Green);
        this->visited = true;
    }
}

void MapField::update_render(sf::RenderTarget* target)
{
    this->shape.setPosition(this->position);
    //this->makeVisited();
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
bool MapField::getVisited()
{
    return this->visited;
}
void MapField::setVisited()
{
    this->visited = true;
}
