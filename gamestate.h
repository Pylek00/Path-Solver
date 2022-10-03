#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "player.h"
#include "playergraphic.h"



class GameState : public State
{
private:
    Player* player;
    PlayerGraphic* gplayer;
   sf::RenderWindow* gameWindow;


public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();


    void update(const float& dt);
    void updateKeyBinds(const float &dt);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
