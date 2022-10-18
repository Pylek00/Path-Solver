#include "playergraphic.h"

PlayerGraphic::PlayerGraphic(Player *object)
{


    this->shape.setRadius(object->getSize());
    this->shape.setPosition(object->getPosition());
    this->shape.setOrigin(sf::Vector2f(object->getSize(), object->getSize()));

    if(!this->texture.loadFromFile("E:/PROGRAMOWANIE/QT_projekty/AMaze/images/ja.PNG"))
    {
        std::cout<<"nie udalo sie wczytac"<<std::endl;
    }
    //this->texture.loadFromFile("E:/PROGRAMOWANIE/QT_projekty/AMaze/images/zombie.png");

    this->shape.setTexture(&texture);
    this->sprite.setOrigin(sf::Vector2f(87,116));
    //this->sprite.setOrigin(sf::Vector2f(24,16));
    this->sprite.setScale(sf::Vector2f(0.1,0.1));
    //this->sprite.setScale(sf::Vector2f(0.5,0.5));
    this->sprite.setColor(sf::Color::White);

    //this->lightShape.setRadius(object->getSeeRange());

    //this->shader.setParameter("halo", 50);

}

PlayerGraphic::~PlayerGraphic()
{

}

void PlayerGraphic::update_render(Player* player, sf::RenderTarget* target,sf::Shader* shader)
{

    //shader->setParameter("hasTexture", true);
    //shader->setParameter("lightPos", true);

    this->shape.setPosition(player->getPosition());
    //this->sprite.setPosition(player->getPosition());

    this->shape.setRotation(player->getRotation());
    //target->draw((this->sprite));
    target->draw(this->shape);
    //target->draw(this->sprite);
}

