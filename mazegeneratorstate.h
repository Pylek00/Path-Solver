#ifndef MAZEGENERATORSTATE_H
#define MAZEGENERATORSTATE_H

#include "state.h"
#include "map.h"
#include "player.h"
#include "playergraphic.h"
#include "particles.h"
#include <list>
#include <queue>


class MazeGeneratorState : public State
{
    sf::RenderWindow* gameWindow;
    sf::View view;
    Map* map;
    sf::Font font;
    sf::Text text;


    std::vector<MapField*> map_ptr;
    sf::RectangleShape c_line;
    sf::Texture texture;

    std::stack<std::pair<int,int>> field_cords;
    std::vector<sf::RectangleShape*> ways_s;
    sf::RectangleShape shape;

    Player* player;
    PlayerGraphic* gplayer;
    std::vector<Particles*>particles;
    sf::Vector2f previous_player_position;

    int vIter;

public:
    MazeGeneratorState(sf::RenderWindow* window,std::stack<State*>* states);
    virtual ~MazeGeneratorState();

    void update(const float& dt);
    void updateKeyBinds(const float &dt);
    void render(sf::RenderTarget* target = nullptr);
    //map

    void update_renderMap();
    void create_maze();
    void update_Particles(int ammount);
};

#endif // MAZEGENERATORSTATE_H
