#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "state.h"
#include "gamestate.h"
#include "playergraphic.h"
#include "map.h"

class Game
{
private:

    //Variables

    sf::Window* wind;
    sf::Event SFevent;
    sf::VideoMode window_bounds;
    sf::RenderWindow* window;
    sf::ContextSettings settings;
    sf::View view;




    float dt;
    sf::Clock dtTime;

    std::stack<State*> states;




    //Initialization
    void initWindow();
    void initObjects();
    void initStates();

    //game objects
    //Player *player;
    //PlayerGraphic* gplayer;


public:



    Game();
    virtual ~Game();

    //Functions

        /**
        * @brief Metoda rozpoczynajaca program
        */
       void run();

       void endApplication();

        //update
       void update();

       void updateSFMLevents();

       void updateDt();

        //render
       void render();

};




#endif // MAINWINDOW_H
