#include "playergraphic.h"

PlayerGraphic::PlayerGraphic(Player *object)
{


    this->shape.setRadius(object->getSize());
    this->shape.setPosition(object->getPosition());
    this->shape.setOrigin(sf::Vector2f(object->getSize(), object->getSize()));

    this->texture.loadFromFile("E:/PROGRAMOWANIE/QT_projekty/AMaze/images/vampire.png");
    this->sprite.setTexture(texture);

    //ja
    //this->sprite.setOrigin(sf::Vector2f(87,116));
    //this->sprite.setScale(sf::Vector2f(0.1,0.1));
    //zombie
    //this->sprite.setOrigin(sf::Vector2f(24,16));
    //this->sprite.setScale(sf::Vector2f(0.5,0.5));

    //vampire
    this->sprite.setScale(sf::Vector2f(0.05,0.05));
    this->sprite.setOrigin(sf::Vector2f(300,250));

    this->sprite.setColor(sf::Color::White);

}

PlayerGraphic::~PlayerGraphic()
{

}

void PlayerGraphic::update_render(Player* player, sf::RenderTarget* target)
{
    this->sprite.setPosition(player->getPosition());
    //this->sprite.setRotation(player->getRotation()-90);
    target->draw((this->sprite));
    //target->draw(this->shape);

}

