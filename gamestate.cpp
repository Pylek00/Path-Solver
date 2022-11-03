#include "gamestate.h"



GameState::GameState(sf::RenderWindow* window,std::stack<State*>* states)
    : State(window,states)
{
    this->gameWindow = window;
    this->map = new Map(window);
    this->map->createMap();
}

GameState::~GameState()
{

    delete this->map;


}


void GameState::update_renderMapFields()
{


    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            this->calculate_mouse_position(sf::Mouse::getPosition(*gameWindow)) < MAP_SIZE_X*MAP_SIZE_Y-1)
    {
    this->map->map_field[this->calculate_mouse_position(sf::Mouse::getPosition(*gameWindow))]->makeWall();
    }
}

int GameState::calculate_mouse_position(sf::Vector2i position)
{

    int i = (position.x-2)/(this->map->map_field[1]->getSize()+5);
    int j = (position.y-2)/(this->map->map_field[1]->getSize()+5);

    return j+i*this->map->mapsize.y;

}

/////////////////////////////////actualizations

void GameState::update(const float& dt)
{
    this->updateKeyBinds(dt);


}
void GameState::updateKeyBinds(const float& dt)
{
    this->checkForQuit();
}

void GameState::render(sf::RenderTarget* target)
{
    this->map->update_renderMap();
    this->update_renderMapFields();

}
////////////////////////////////////////////////

//////////////////////////inits

void GameState::initShaders()
{
    if(!this->shader.loadFromFile("vertex_shader.vert", "fragment_shader.frag"))
    {
        std::cout<<"Nie udało sie wczytac cieniowania :("<<std::endl;
    }
}


