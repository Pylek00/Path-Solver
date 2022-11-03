#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
//#include "mapfield.h"
#include "map.h"


class GameState : public State
{
private:

    sf::RenderWindow* gameWindow;
    Map* map;
    sf::Shader shader;


public:
    GameState(sf::RenderWindow* window,std::stack<State*>* states);
    virtual ~GameState();

    void update(const float& dt);
    void updateKeyBinds(const float &dt);
    void render(sf::RenderTarget* target = nullptr);
    //map
    void update_renderMapFields();
    int calculate_mouse_position(sf::Vector2i position);
    //inits

    void initShaders();
};

#endif // GAMESTATE_H
