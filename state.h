#ifndef STATE_H
#define STATE_H

#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream>
#include<stack>
#include<random>
#include<map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>


class State
{
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;    


protected:
    std::stack<State*>* states;
    bool quit;

public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit() const;
    virtual void endState();
    virtual void checkForQuit();
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

#endif // STATE_H
