#include "player.h"

Player::Player(int speed, int size)
{
    this->speed = speed;
    this->size = size;
    this->position = sf::Vector2f(15,315);
    this->seeRange = 100;
    this->rotation = 0;

    for(int i=0;i<sizeof(this->direction); i++)
    {
        this->direction[i] = false;
    }
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
        this->direction[0] = true;
    }
    else{
        this->direction[0] = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->direction[1] = true;
    }
    else{
        this->direction[1] = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->direction[2] = true;
    }
    else{
        this->direction[2] = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->direction[3] = true;
    }
    else{
        this->direction[3] = false;
    }

    this->position.x += this->speed*(this->direction[0]-this->direction[1]);
    this->position.y += this->speed*(this->direction[3]-this->direction[2]);
    //std::cout<<this->direction[3]-this->direction[2]<<std::endl;
    if(this->position.x+size > this->mapSize.x)
            {
                this->position.x = this->mapSize.x-this->size;
            }
    else if(this->position.x < this->size)
            {
               this->position.x = this->size;
            }
    if(this->position.y+size > this->mapSize.y)
            {
                this->position.y = this->mapSize.y-this->size;
            }
    else if(this->position.y < this->size)
            {
               this->position.y = this->size;
            }
    if((this->direction[0]-this->direction[1] == 0 && this->direction[3]-this->direction[2] < 1) ||
       (this->direction[0]-this->direction[1] == 0 && this->direction[3]-this->direction[2] == -1))
    {
        this->rotation = 0;
    }
    else if(this->direction[0]-this->direction[1] == 1 && this->direction[3]-this->direction[2] == 0)
    {
        this->rotation = 90;
    }
    else if(this->direction[0]-this->direction[1] == -1 && this->direction[3]-this->direction[2] == 0)
    {
        this->rotation = -90;
    }
    else if(this->direction[0]-this->direction[1] == 0 && this->direction[3]-this->direction[2] == 1)
    {
        this->rotation = 180;
    }
    else if(this->direction[0]-this->direction[1] == 1 && this->direction[3]-this->direction[2] == 1)
    {
        this->rotation = 135;
    }
    else if(this->direction[0]-this->direction[1] == 1 && this->direction[3]-this->direction[2] == -1)
    {
        this->rotation = 45;
    }
    else if(this->direction[0]-this->direction[1] == -1 && this->direction[3]-this->direction[2] == 1)
    {
        this->rotation = -135;
    }
    else if(this->direction[0]-this->direction[1] == -1 && this->direction[3]-this->direction[2] == -1)
    {
        this->rotation = -45;
    }


//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//    {
//        this->position.x += this->speed;
//        this->rotation = 90;
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//        {
//            this->rotation = 45;
//        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//        {
//            this->rotation = 135;
//        }


//        if(this->position.x+size > this->mapSize.x)
//        {
//            this->position.x = this->mapSize.x-this->size;
//        }
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//    {
//        this->position.x -= this->speed;
//        this->rotation = -90;
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//        {
//            this->rotation = -45;
//        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//        {
//            this->rotation = -135;
//        }
//        if(this->position.x < this->size)
//        {
//            this->position.x = this->size;
//        }
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//    {
//        this->position.y -= this->speed;
//        this->rotation = 0;
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//        {
//            this->rotation = -45;
//        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//        {
//            this->rotation = 45;
//        }
//        if(this->position.y < this->size)
//        {
//            this->position.y = this->size;
//        }
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//    {
//        this->position.y += this->speed;
//        this->rotation = 180;
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//        {
//            this->rotation = -135;
//        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//        {
//            this->rotation = 135;
//        }
//        if(this->position.y < this->size)
//        {
//            this->position.y = this->size;
//        }
//        if(this->position.y > this->mapSize.y-this->size)
//        {
//            this->position.y = this->mapSize.y-this->size;
//        }
//    }
}




int Player::getSeeRange()
{
    return this->seeRange;
}

float Player::getRotation()
{
    return this->rotation;
}
