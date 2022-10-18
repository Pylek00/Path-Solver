#include "state.h"

State::State(sf::RenderWindow* window,std::stack<State*>* states)
{
    this->window = window;
    this->quit = false;
    this->states = states;
}
State::~State(){

}


void State::update(const float& dt)
{

}

void State::render(sf::RenderTarget* target)
{

}

const bool& State::getQuit() const
{
    return this->quit;
}

void State::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }
}

void State::endState()
{
    std::cout<<"Ending game state"<<std::endl;
}
