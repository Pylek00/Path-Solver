#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "state.h"

class GraphicObject
{
public:
    GraphicObject();
    virtual ~GraphicObject();



    sf::Sprite sprite;
    sf::Texture texture;
    sf::Shader shader;


    //void draw(sf::RenderTarget* target);
};

#endif // GRAPHICOBJECT_H
