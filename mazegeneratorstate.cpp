#include "mazegeneratorstate.h"



MazeGeneratorState::MazeGeneratorState(sf::RenderWindow* window,std::stack<State*>* states)
    :State(window,states)
{
    this->gameWindow = window;


    this->map = new Map(window);
    this->map_ptr = this->map->createMap();
    this->player = new Player(3,8);
    this->player->setPosition(sf::Vector2f(15,15));

    this->gplayer = new PlayerGraphic(this->player);

    this->font.loadFromFile("E:/PROGRAMOWANIE/QT_projekty/AMaze/Graphics/28_Days_Later.ttf");

    if(!this->texture.loadFromFile("E:/PROGRAMOWANIE/QT_projekty/AMaze/images/floor.png"))
    {
      std::cout<<"Nie udalo sie wczytac podlogi!"<<std::endl;
    }
    this->text.setFont(this->font);
    this->c_line = sf::RectangleShape(sf::Vector2f(45,20));
    this->c_line.setOrigin(10,10);
    this->field_cords.push({0,0});
    this->vIter = this->map_ptr.size();


    this->map_ptr[0]->setVisited();
    this->vIter --;



    this->create_maze();




}

MazeGeneratorState::~MazeGeneratorState()
{
    this->gameWindow->setView(this->gameWindow->getDefaultView());

    delete this->map;
    delete this-> player;
    delete this->gplayer;
    this->map_ptr.clear();
    this->ways_s.clear();

    while(!this->particles.empty())
    {
        delete this->particles.back();
        this->particles.pop_back();
    }
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
    //update player
    this->previous_player_position = this->player->getPosition();

    this->player->move(this->gameWindow);

    bool canMove = false;
    for(int i=0;i<this->ways_s.size();i++)
    {
//        if(this->ways_s[i]->getGlobalBounds().contains(this->player->getPosition()))
//        {
//            canMove = true;
//            break;
//        }
        if(this->ways_s[i]->getGlobalBounds().contains(this->player->getPosition().x-7,this->player->getPosition().y-7)&&
           this->ways_s[i]->getGlobalBounds().contains(this->player->getPosition().x-7,this->player->getPosition().y+7)&&
           this->ways_s[i]->getGlobalBounds().contains(this->player->getPosition().x+7,this->player->getPosition().y-7)&&
           this->ways_s[i]->getGlobalBounds().contains(this->player->getPosition().x+7,this->player->getPosition().y+7))
        {
            canMove = true;
            break;
        }

    }
    if(canMove == false){
        this->player->setPosition(this->previous_player_position);
    }
    //view



    //update player

}
void MazeGeneratorState::updateKeyBinds(const float& dt)
{
    this->checkForQuit();
}

void MazeGeneratorState::render(sf::RenderTarget* target)
{
    this->update_renderMap();
    this->update_Particles(150);

    this->gplayer->update_render(this->player,this->gameWindow);



    this->gameWindow->setView(view);
    this->view.setSize(sf::Vector2f(160,120));
    this->view.setCenter(this->player->getPosition());
    //this->update_renderMapFields();

}
void MazeGeneratorState::update_renderMap()
{
    for(int i=0;i<=this->map_ptr.size();i++)
    {
        //this->map_ptr[i]->update_render(this->gameWindow);
        if(this->player->getPosition().x > this->ways_s[i]->getPosition().x-this->player->getSeeRange()-10&&
           this->player->getPosition().x < this->ways_s[i]->getPosition().x+this->player->getSeeRange()+10&&
           this->player->getPosition().y > this->ways_s[i]->getPosition().y-this->player->getSeeRange()&&
           this->player->getPosition().y < this->ways_s[i]->getPosition().y+this->player->getSeeRange())
        {
        this->gameWindow->draw(*this->ways_s[i]);
        }
    }
    this->gameWindow->draw(this->shape);

}


////////////////////////////////////////////////
void MazeGeneratorState::create_maze()
{
    sf::RectangleShape* r = new sf::RectangleShape(sf::Vector2f(45,20));
    r->setOrigin(10,10);
    r->setRotation(180);
    r->setPosition(15,15);
    r->setTexture(&texture);
    r->setTextureRect(sf::IntRect(0, 0, 1024, 1024));
    this->ways_s.push_back(r);

    r = new sf::RectangleShape(sf::Vector2f(45,20));
    r->setOrigin(10,10);
    r->setRotation(0);
    r->setTexture(&texture);
    r->setTextureRect(sf::IntRect(0, 0, 1024, 1024));
    r->setPosition(this->map_ptr[this->map_ptr.size()-1]->getPosition().x,this->map_ptr[this->map_ptr.size()-1]->getPosition().y);
    this->ways_s.push_back(r);

    std::vector<int> neighbours;
    srand(time(NULL));
    while(this->vIter > 0)
    {

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
                r = new sf::RectangleShape(sf::Vector2f(45,20));
                r->setOrigin(10,10);
                r->setTexture(&texture);
                r->setTextureRect(sf::IntRect(0, 0, 1024, 1024));
                r->setRotation(-90);
                r->setPosition(map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().x,
                               map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().y);
                this->ways_s.push_back(r);



                this->field_cords.push(std::make_pair(this->field_cords.top().first,this->field_cords.top().second-1));
                this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->makeVisited();
                this->vIter --;


                break;
            case 1://down
                r = new sf::RectangleShape(sf::Vector2f(45,20));
                r->setOrigin(10,10);
                r->setTexture(&texture);
                r->setTextureRect(sf::IntRect(0, 0, 1024, 1024));
                r->setRotation(90);
                r->setPosition(map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().x,
                               map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().y);
                this->ways_s.push_back(r);

                this->field_cords.push(std::make_pair(this->field_cords.top().first,this->field_cords.top().second+1));
                this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->makeVisited();
                this->vIter --;
                break;
            case 2:// right ->
                r = new sf::RectangleShape(sf::Vector2f(45,20));
                r->setOrigin(10,10);
                r->setTexture(&texture);
                r->setTextureRect(sf::IntRect(0, 0, 1024, 1024));
                r->setRotation(0);
                r->setPosition(map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().x,
                               map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().y);
                this->ways_s.push_back(r);

                this->field_cords.push(std::make_pair(this->field_cords.top().first+1,this->field_cords.top().second));
                this->map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->makeVisited();
                this->vIter --;
                break;
            case 3:// <- left
                r = new sf::RectangleShape(sf::Vector2f(45,20));
                r->setOrigin(10,10);
                r->setTexture(&texture);
                r->setTextureRect(sf::IntRect(0, 0, 1024, 1024));
                r->setRotation(180);
                r->setPosition(map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().x,
                               map_ptr[this->field_cords.top().first*MAP_SIZE_Y + this->field_cords.top().second]->getPosition().y);
                this->ways_s.push_back(r);

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

void MazeGeneratorState::update_Particles(int ammount)
{
    if(this->particles.size() < ammount){
        this->particles.push_back(new Particles(this->player->getPosition()));


    }
    for(int i=this->particles.size()-1;i >= 0; i--)
    {
        this->particles[i]->update_render(this->player,this->gameWindow);
    }
}
