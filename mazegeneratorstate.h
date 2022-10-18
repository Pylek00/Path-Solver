#ifndef MAZEGENERATORSTATE_H
#define MAZEGENERATORSTATE_H

#include "state.h"
#include "map.h"

#include <string>
#include <dos.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <iostream>

#include <cstdlib>
#include <ctime>

class MazeGeneratorState : public State
{
    struct ways
    {
        int rotation;
        int x,y;
    };

    sf::RenderWindow* gameWindow;
    Map* map;
    sf::Font font;
    sf::Text text;

    std::vector<MapField*> map_ptr;
    sf::RectangleShape* line;

    std::stack<std::pair<int,int>> field_cords;
    std::vector<ways> ways_s;


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
