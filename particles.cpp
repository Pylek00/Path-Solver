#include "particles.h"

Particles::Particles(sf::Vector2f position)
{
    srand(time(NULL));

    this->size = (float)(rand() % 90 + 40)/100;               //wielkosc czasteczki
    this->velocity = this->size*(float)(rand() % 10)/200;   //predkosc
    this->duration = rand() % 50 + 50;                      //czas trwania w cyklach
    this->distance = (float)(rand() % 200)/10;                //przebyty dystans(poczatek losowo geneowany

    this->shape.setRadius(this->size);
    //this->shape.setFillColor(sf::Color(0,0,rand()%255,rand()%255));
    this->shape.setFillColor(sf::Color(0,0,rand()%255,100 + rand()%155));
    this->part_direction = (rand() % 360)*M_PI/180;
    this->position = position;

}

Particles::~Particles()
{

}

void Particles::update_render(Player* player, sf::RenderTarget* target)
{
    //this->position = player->getPosition();

    if(this->distance >= this->velocity*(float)this->duration)
    {
        this->shape.setPosition(player->getPosition());
        this->position = player->getPosition();
        this->part_direction = (rand() % 360)*M_PI/180;
        this->distance = 0;
    }


    this->distance += this->velocity;
    this->position.x += this->distance * sin(this->part_direction);
    this->position.y += this->distance * cos(this->part_direction);
    this->shape.setPosition(this->position.x,this->position.y);

    target->draw(this->shape);

}
