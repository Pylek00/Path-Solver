#include "playergraphic.h"

PlayerGraphic::PlayerGraphic(Player *object)
{


    this->shape.setRadius(object->getSize());
    this->shape.setPosition(object->getPosition());
    this->shape.setOrigin(sf::Vector2f(object->getSize(), object->getSize()));

}

PlayerGraphic::~PlayerGraphic()
{


}

void PlayerGraphic::update_render(Player* player, sf::RenderTarget* target)
{
    this->shape.setPosition(player->getPosition());
    target->draw(this->shape);
}

