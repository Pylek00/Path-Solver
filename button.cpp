#include "button.h"



Button::Button(float x, float y,float width, float height,
                    std::string text,sf::Color idleColor,
               sf::Color hoverColor, sf::Color activeColor,
               bool isvisible, sf::Font* font)
{
        this->idleColor = idleColor;
        this->hoverColor = hoverColor;
        this->activeColor = activeColor;
        this->buttonState = IDLE_BTN;
        this->isVisible = isvisible;



        this->shape.setPosition(sf::Vector2f(x, y));
        this->shape.setSize(sf::Vector2f(width, height));
        this->shape.setOrigin(sf::Vector2f(width / 2, height / 2));


        this->font = font;
        this->text.setFont(*this->font);
        this->text.setString(text);

        this->text.setCharacterSize(this->textSize);
        this->text.setColor(sf::Color::Black);
        //this->text.setFont(sf::Font::)
        this->text.setPosition(
            this->shape.getPosition().x - (textSize/4*text.size()),
            this->shape.getPosition().y - this->textSize / 2);

}
Button::~Button()
{
    //delete font;
}

void Button::update(const sf::Vector2f mousePos)
{
    //idle
    this->buttonState = IDLE_BTN;
    //hover
    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = HOVER_BTN;
        //press
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            this->buttonState = PRESSED_BTN;
        }

    }
    switch (this->buttonState)
    {
    case IDLE_BTN:
        this->shape.setFillColor(this->idleColor);
        break;
    case HOVER_BTN:
        this->shape.setFillColor(this->hoverColor);
        break;
    case PRESSED_BTN:
        this->shape.setFillColor(this->activeColor);
        break;

    }
}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->text);
}

bool Button::isPressed()
{
    if (buttonState == PRESSED_BTN )
    {

        return true;
    }
    else
        return false;
}
bool Button::isClicked(const sf::Vector2f mousePos)
{
    if (this->shape.getGlobalBounds().contains(mousePos)
            && buttonState == PRESSED_BTN
            && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {return true;}
    else    {return false;}
}


