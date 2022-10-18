#include "mazegeneratorstate.h"



MazeGeneratorState::MazeGeneratorState(sf::RenderWindow* window,std::stack<State*>* states)
    :State(window,states)
{
    this->gameWindow = window;
    this->map = new Map(window);
    this->map_ptr = this->map->createMap();

    this->font.loadFromFile("E:/PROGRAMOWANIE/QT_projekty/AMaze/Graphics/28_Days_Later.ttf");
    this->text.setFont(this->font);
    this->line = new sf::RectangleShape(sf::Vector2f(45,20));
    this->line->setOrigin(10,10);
    this->field_cords.push({0,0});
    this->vIter = this->map_ptr.size();


    this->map_ptr[0]->setVisited();
    this->vIter --;

    this->create_maze();


}

MazeGeneratorState::~MazeGeneratorState()
{
    delete this->map;
    delete this->line;

    this->map_ptr.clear();
}




//int MazeGeneratorState::calculate_mouse_position(sf::Vector2i position)
//{
//    int i = (position.x-2)/(this->map->map_field[1]->getSize()+5);
//    int j = (position.y-2)/(this->map->map_field[1]->getSize()+5);
//    return j+i*this->map->mapsize.y;
//}

/////////////////////////////////actualizations

void MazeGeneratorState::update(const float& dt)
{
    this->updateKeyBinds(dt);


}
void MazeGeneratorState::updateKeyBinds(const float& dt)
{
    this->checkForQuit();
}

void MazeGeneratorState::render(sf::RenderTarget* target)
{
    this->update_render();
    //this->update_renderMapFields();

}
void MazeGeneratorState::update_render()
{
    for(int i=0;i<this->map_ptr.size();i++)
    {
        this->map_ptr[i]->update_render(this->gameWindow);


        this->line->setRotation(this->ways_s[i-1].rotation);
        this->line->setPosition(this->ways_s[i-1].x,this->ways_s[i-1].y);
        this->gameWindow->draw(*line);
    }



}


////////////////////////////////////////////////
void MazeGeneratorState::create_maze()
{
    ways w;
    w.rotation = 180;
    w.x = 15;
    w.y = 15;
    this->ways_s.push_back(w);
    w.rotation = 0;
    w.x = this->map_ptr[this->map_ptr.size()-1]->getPosition().x;
    w.y = this->map_ptr[this->map_ptr.size()-1]->getPosition().y;
    this->ways_s.push_back(w);

    std::vector<int> neighbours;
    srand(time(NULL));
    while(this->vIter > 0)
    {
        std::cout<<this->ways_s.size()<<std::endl;
        neighbours.clear();
        //north
        if(this->field_cords.top().second > 0)
        {
            if(!(this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second -1]->getVisited()))
            {
                neighbours.push_back(0);
            }
        }
        //south
        if(this->field_cords.top().second < MAP_SIZE_Y-1)
        {
            if(!(this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second +1]->getVisited()))
            {
                neighbours.push_back(1);
            }
        }
        //east
        if(this->field_cords.top().first < MAP_SIZE_X -1)
        {
            if(!(this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second + MAP_SIZE_Y]->getVisited()))
            {
                neighbours.push_back(2);
            }
        }
        //west
        if(this->field_cords.top().first > 0)
        {
            if(!(this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second - MAP_SIZE_Y]->getVisited()))
            {
                neighbours.push_back(3);
            }
        }

        if(!neighbours.empty())
        {
            int cell_dir = neighbours[rand() % neighbours.size()];

            switch(cell_dir)
            {
            case 0://up
                w.rotation = -90;
                w.x = map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().x;
                w.y = map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().y;
                this->ways_s.push_back(w);

                this->field_cords.push(std::make_pair(this->field_cords.top().first,this->field_cords.top().second-1));
                this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->makeVisited();
                this->vIter --;
                break;
            case 1://down
                w.rotation = 90;
                w.x = map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().x;
                w.y = map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().y;
                this->ways_s.push_back(w);

                this->field_cords.push(std::make_pair(this->field_cords.top().first,this->field_cords.top().second+1));
                this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->makeVisited();
                this->vIter --;
                break;
            case 2:// right ->
                w.rotation = 0;
                w.x = map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().x;
                w.y = map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().y;
                this->ways_s.push_back(w);

                this->field_cords.push(std::make_pair(this->field_cords.top().first+1,this->field_cords.top().second));
                this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->makeVisited();
                this->vIter --;
                break;
            case 3:// <- left
                w.rotation = 180;
                w.x = map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().x;
                w.y = map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().y;
                this->ways_s.push_back(w);

                this->field_cords.push(std::make_pair(this->field_cords.top().first-1,this->field_cords.top().second));
                this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->makeVisited();
                this->vIter --;
                break;
            default:
                break;
            }
        }
        else
        {
            this->field_cords.pop();
        }


    }
}
