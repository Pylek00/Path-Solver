#include "pathfinder.h"

PathFinder::PathFinder(sf::RenderWindow* window,std::stack<State*>* states)
    : State(window,states)
{

}

PathFinder::~PathFinder()
{

}
