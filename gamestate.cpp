#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window)
    : State(window)
{
    this->player = new Player(5,10);
    this->gplayer = new PlayerGraphic(this->player);
    this->gameWindow = window;

}

GameState::~GameState()
{
    delete player;
    delete gplayer;
    delete gameWindow;
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
    this->gplayer->update_render(this->player, this->gameWindow);

}
