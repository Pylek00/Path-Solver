#include "mainwindow.h"
#include "gamestate.h"




//Initialize functions


void Game::initWindow(){



    std::ifstream ifs("AMaze/Config/window.txt");
    std::string title = "Maze Explorer";
    window_bounds.width = 805;
    window_bounds.height = 605;
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    settings.antialiasingLevel = 8;

/*
    if(ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }
    ifs.close();
*/
    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);



}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

void Game::initObjects()
{
    //this->player = new Player(10,10);
    //this->gplayer = new PlayerGraphic(this->player);
}

Game::Game()
{
    this->initWindow();
    this->initStates();

    //this->wind = this->window;
    this->initObjects();
}


Game::~Game()
{
    delete this->window;
    delete this->wind;
    while(!this->states.empty())
    {
       delete this->states.top();
       this->states.pop();
    }
    //delete player;
    //delete gplayer;

}

void Game::run()
{
    while (this->window->isOpen())
        {
            this->update();
            this->render();
        }
}



void Game::update()
{

    this->updateDt();


    if(!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->endApplication();
        this->window->close();
    }
    this->updateSFMLevents();
}


void Game::render()
{

    this->window->clear();
    /////////////////////////////////////////
    //player render
    //this->gplayer->update_render(this->player,this->window);



    if(!this->states.empty())
    {
        this->states.top()->render(this->window);
    }



    //////////////////////////////////////////////////
    this->window->display();

}

void Game::updateSFMLevents()
{

    while(this->window->pollEvent(this->SFevent))
    {
        if(this->SFevent.type == sf::Event::Closed)
            {
            this->endApplication();
            this->window->close();}
    }

    //update player keybinds
    //this->player->move(this->window);

}

void Game::updateDt()
{
    this->dt = this->dtTime.restart().asSeconds();

    //system("cls");
    std::cout <<"Frames per second: "<<1/this->dt << std::endl;
}

void Game::endApplication()
{
    std::cout<<"Ending the application! :)"<<std::endl;
}






//Functions
