#ifndef BUTTON_H
#define BUTTON_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>


class Button
{
private:
    sf::Font* font;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

    const int textSize = 30;

    enum ButtonState {IDLE_BTN = 0, HOVER_BTN, PRESSED_BTN };
    short unsigned buttonState;


    sf::Text text;
    sf::RectangleShape shape;


public:
    Button(float x, float y,float width, float height,
           std::string text, sf::Color idleColor,
           sf::Color hoverColor, sf::Color activeColor,
           bool isvisible, sf::Font* font);
    virtual ~Button();

    int getButtonState();
    void setButtonState(int bState);

    void update(const sf::Vector2f mousePosition);
    void render(sf::RenderTarget* target);
    bool isPressed();
    bool isClicked(const sf::Vector2f mousePos);
    bool isVisible;

};

#endif // BUTTON_H
