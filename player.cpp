#include "player.h"

Player::Player(int speed, int size)
{
    this->speed = speed;
    this->size = size;
    this->position = sf::Vector2f(50,50);

}
Player::~Player()
{

}




//getters
sf::Vector2f Player::getPosition()
{
    return this->position;
}
int Player::getSize()
{
    return this->size;
}

//setters
void Player::setPosition(sf::Vector2f position)
{
    this->position = position;
}
void Player::setSpeed(int speed)
{
    this->speed = speed;
}

void Player::setSize(int size)
{
    this->size = size;
}

void Player::move(sf::RenderTarget* target)
{
    this->mapSize = target->getSize();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->position.x += this->speed;
        if(this->position.x+size > this->mapSize.x)
        {
            this->position.x = this->mapSize.x-this->size;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->position.x -= this->speed;
        if(this->position.x < this->size)
        {
            this->position.x = this->size;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->position.y -= this->speed;
        if(this->position.y < this->size)
        {
            this->position.y = this->size;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->position.y += this->speed;
        if(this->position.y > this->mapSize.y-this->size)
        {
            this->position.y = this->mapSize.y-this->size;
        }
    }





}
