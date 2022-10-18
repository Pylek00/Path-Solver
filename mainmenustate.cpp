#include "mainmenustate.h"
#include "gamestate.h"
#include "mazegeneratorstate.h"

MainMenuState::MainMenuState(sf::RenderWindow* window,std::stack<State*>* states)
    : State(window,states)
{
    sf::IntRect rect(0,0,1280,1000);
    this->texture.loadFromFile("E:/PROGRAMOWANIE/QT_projekty/AMaze/Graphics/MainMenu.jpg");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(0,0);
    this->sprite.setTextureRect(rect);
    this->sprite.setScale(sf::Vector2f(0.76,0.80));
    this->width = rect.width;
    this->height = rect.height;
    this->window = window;
    this->font.loadFromFile("E:/PROGRAMOWANIE/QT_projekty/AMaze/Graphics/28_Days_Later.ttf");

    this->text.setString("Way founder");
    this->text.setFont(this->font);
    this->text.setColor(sf::Color::White);
    this->text.setCharacterSize(150);
    this->text.setPosition(100,0);


    this->buttonStart = new Button(200, 250, 200, 100,
            "Start Game",
            sf::Color(198, 206, 206,200),
            sf::Color(245, 245, 220,200),
            sf::Color(54, 69, 79,200),
            true, &font);


     this->buttonOptions = new Button(200, 450, 200, 100,
            "Options",
            sf::Color(198, 206, 206, 200),
            sf::Color(245, 245, 220, 200),
            sf::Color(54, 69, 79, 200),
            true, &font);

    this->buttonExit = new Button(200, 650, 200, 100,
            "Exit Game",
            sf::Color(198, 206, 206,200),
            sf::Color(245, 245, 220,200),
            sf::Color(54, 69, 79,200),
            true, &font);
    this->buttonPathFinder = new Button(500, 250, 200, 100,
            "Path Finder",
            sf::Color(198, 206, 206,200),
            sf::Color(245, 245, 220,200),
            sf::Color(54, 69, 79,200),
            false, &font);
    this->buttonMazeGenerator = new Button(800, 250, 200, 100,
            "Maze Generator",
            sf::Color(198, 206, 206,200),
            sf::Color(245, 245, 220,200),
            sf::Color(54, 69, 79,200),
            false, &font);
}

MainMenuState::~MainMenuState()
{
    delete this->buttonStart;
    delete this->buttonOptions;
    delete this->buttonExit;
    delete this->buttonPathFinder;
    delete this->buttonMazeGenerator;
}

void MainMenuState::update(const float& dt)
{
    this->updateButtons();
    //this->checkForQuit();

}

void MainMenuState::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
    target->draw(this->text);

    this->buttonStart->render(this->window);
    this->buttonOptions->render(this->window);
    this->buttonExit->render(this->window);

    if(this->buttonPathFinder->isVisible)
    {
        this->buttonPathFinder->render(this->window);
    }
    if(this->buttonMazeGenerator->isVisible)
    {
        this->buttonMazeGenerator->render(this->window);
    }
}

void MainMenuState::updateButtons()
{
    ////////////////////////clicking buttons consequences
    if(this->buttonStart->isClicked(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
    {
        this->buttonPathFinder->isVisible = !(this->buttonPathFinder->isVisible);
        this->buttonMazeGenerator->isVisible = !(this->buttonMazeGenerator->isVisible);
    }
    else if(this->buttonPathFinder->isClicked(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
    {
        this->buttonPathFinder->isVisible = !(this->buttonPathFinder->isVisible);
        this->buttonMazeGenerator->isVisible = !(this->buttonMazeGenerator->isVisible);
        this->states->push(new GameState(this->window,this->states));
    }
    else if(this->buttonMazeGenerator->isClicked(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
    {
        this->buttonPathFinder->isVisible = !(this->buttonPathFinder->isVisible);
        this->buttonMazeGenerator->isVisible = !(this->buttonMazeGenerator->isVisible);
        this->states->push(new MazeGeneratorState(this->window,this->states));
    }
    else if(this->buttonExit->isClicked(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
    {
        this->quit = true;
    }
////////////////////////////////end clicking buttons


////////////////////////////////updating buttons
    this->buttonStart->update(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    this->buttonOptions->update(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    this->buttonExit->update(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window)));

    if(this->buttonPathFinder->isVisible)
    {
        this->buttonPathFinder->update(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    }
    if(this->buttonMazeGenerator->isVisible)
    {
        this->buttonMazeGenerator->update(this->window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    }
///////////////////////////////end updating buttons
}
