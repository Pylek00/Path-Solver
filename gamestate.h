#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "player.h"
#include "playergraphic.h"
#include "mapfield.h"
#include "map.h"


class GameState : public State
{
private:
    Player* player;
    PlayerGraphic* gplayer;
    sf::RenderWindow* gameWindow;
    sf::Vector2i mapsize;
    sf::Vector2i objectSize;
    std::vector<MapField*> map_field;
    Map* map;
    sf::Vector2f current_player_position;


public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    void update(const float& dt);
    void updateKeyBinds(const float &dt);
    void render(sf::RenderTarget* target = nullptr);
    //map
    void createMap();
    void update_renderMap();
    int calculate_mouse_position(sf::Vector2i position);
    int calculate_player_location(sf::Vector2f position);
};

#endif // GAMESTATE_H
