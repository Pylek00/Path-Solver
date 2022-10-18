#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "state.h"
#include "button.h"

class MainMenuState : public State
{
public:
    MainMenuState(sf::RenderWindow* window,std::stack<State*>* states);

    virtual ~MainMenuState();

    void update(const float& dt);
    //void updateKeyBinds(const float &dt);
    void render(sf::RenderTarget* target = nullptr);


private:
    sf::Texture texture;
    sf::Text text;
    sf::Sprite sprite;
    sf::Font font;

    sf::RenderWindow* window;

    int width;
    int height;

    Button* buttonStart;
    Button* buttonOptions;
    Button* buttonExit;
    Button* buttonPathFinder;
    Button* buttonMazeGenerator;


    void updateButtons();

};

#endif // MAINMENUSTATE_H
