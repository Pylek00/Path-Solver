#include "gamestate.h"



GameState::GameState(sf::RenderWindow* window)
    : State(window)
{
    this->player = new Player(3,5);
    this->gplayer = new PlayerGraphic(this->player);
    this->gameWindow = window;
    this->mapsize = sf::Vector2i(40,30);
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
    delete map;
}

void GameState::createMap()
{
    for(int i=0;i < this->mapsize.x;i++)
    {
        for(int j=0; j<this->mapsize.y;j++)
        {         
            this->map_field.push_back(new MapField(sf::Vector2f(5+i*25,5+j*25)));            
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

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
    this->map_field[this->calculate_mouse_position(sf::Mouse::getPosition(*gameWindow))]->makeWall();
        //std::cout<<"AAAAAAAAAAAAAAAAAAAAAAA"<<std::endl;
        //std::cout<<sf::Mouse::getPosition().x<<" "<<sf::Mouse::getPosition().x<<std::endl;
    }
}
int GameState::calculate_player_location(sf::Vector2f position)
{

    int i = (position.x-2)/(this->map_field[1]->getSize()+5);
    int j = (position.y-2)/(this->map_field[1]->getSize()+5);
    return j+i*this->mapsize.y;
}
int GameState::calculate_mouse_position(sf::Vector2i position)
{
    int i = (position.x-2)/(this->map_field[1]->getSize()+5);
    int j = (position.y-2)/(this->map_field[1]->getSize()+5);
    return j+i*this->mapsize.y;
}

void GameState::update(const float& dt)
{
    this->updateKeyBinds(dt);


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


