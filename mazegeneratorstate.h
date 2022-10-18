#ifndef MAZEGENERATORSTATE_H
#define MAZEGENERATORSTATE_H

#include "state.h"
#include "map.h"
#include "player.h"
#include "playergraphic.h"


class MazeGeneratorState : public State
{
    sf::RenderWindow* gameWindow;
    Map* map;
    sf::Font font;
    sf::Text text;

    std::vector<MapField*> map_ptr;
    sf::RectangleShape c_line;

    std::stack<std::pair<int,int>> field_cords;
    std::vector<sf::RectangleShape*> ways_s;


    Player* player;
    PlayerGraphic* gplayer;
    sf::Vector2f previous_player_position;

    int vIter;

public:
    MazeGeneratorState(sf::RenderWindow* window,std::stack<State*>* states);
    virtual ~MazeGeneratorState();

    void update(const float& dt);
    void updateKeyBinds(const float &dt);
    void render(sf::RenderTarget* target = nullptr);
    //map

    void update_render();
    void create_maze();
};

#endif // MAZEGENERATORSTATE_H
