#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "player.h"
#include "playergraphic.h"
//#include "mapfield.h"
#include "map.h"


class GameState : public State
{
private:
    Player* player;
    PlayerGraphic* gplayer;
    sf::RenderWindow* gameWindow;
    Map* map;
    sf::Vector2f current_player_position;

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
    int calculate_player_location(sf::Vector2f position);
    //inits

    void initShaders();
};

#endif // GAMESTATE_H
