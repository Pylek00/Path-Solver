#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window)
    : State(window)
{
    this->player = new Player(2,5);
    this->gplayer = new PlayerGraphic(this->player);
    this->gameWindow = window;
    this->mapsize = sf::Vector2i(32,24);
    this->createMap();
}

GameState::~GameState()
{
    delete player;
    delete gplayer;
    delete gameWindow;
    for(int i=0;i < map_field.size();i++)
    {
        delete this->map_field[i];
    }

    this->map_field.clear();
}

void GameState::createMap()
{
    for(int i=0;i < this->mapsize.x;i++)
    {
        for(int j=0; j<this->mapsize.y;j++)
        {
            //this->mapf_h = new MapField(sf::Vector2f(5+i*25,5+j*25));
            this->map_field.push_back(new MapField(sf::Vector2f(5+i*25,5+j*25)));

            //std::cout<<i<<" , "<<j<<" , "<<this->map_field.size()<<std::endl;
        }
    }
}
void GameState::update_renderMap()
{
    for(int i=0;i<this->map_field.size();i++)
    {
        this->map_field[i]->update_render(this->gameWindow);
    }
    this->map_field[calculate_player_location(this->player->getPosition())]->makeVisited();

}
int GameState::calculate_player_location(sf::Vector2f position)
{

    int i = (position.x-2)/(this->map_field[1]->getSize()+5);
    int j = (position.y-2)/(this->map_field[1]->getSize()+5);
    return j+i*this->mapsize.y;
}

void GameState::update(const float& dt)
{
    this->updateKeyBinds(dt);

    //std::cout<<"Hello Game State"<<std::endl;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout<<"AAAAAAAAAAAAAAAA"<<std::endl;
    }
}
void GameState::updateKeyBinds(const float& dt)
{
    this->player->move(this->gameWindow);
    this->checkForQuit();
}

void GameState::render(sf::RenderTarget* target)
{
    this->update_renderMap();
    this->gplayer->update_render(this->player, target);

}
