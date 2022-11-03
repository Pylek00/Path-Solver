#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "state.h"

class PathFinder : public State
{
public:
    PathFinder(sf::RenderWindow* window,std::stack<State*>* states);
    virtual ~PathFinder();
};

#endif // PATHFINDER_H
