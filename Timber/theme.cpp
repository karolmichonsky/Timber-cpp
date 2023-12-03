#include "Theme.h"

Theme::Theme(sf::RenderWindow* window, Game* game)
{

	this->window = window;
	initCheckBox(styleClassic, 150, sf::Color(0, 255, 127));
	initCheckBox(styleWinter, 300, sf::Color(255, 250, 250));
	initCheckBox(styleHell, 450, sf::Color(255, 127, 80));
	initCheckBox(styleVoid, 600, sf::Color(138, 43, 226));
	initBack();
}

void Theme::initCheckBox(sf::RectangleShape& box, int boxXPos, sf::Color boxColor)
{
	box.setFillColor(boxColor);
	box.setOutlineColor(sf::Color(220, 220, 220));
	box.setOutlineThickness(2);
	box.setPosition(boxXPos, 250);
	box.setSize(sf::Vector2f(50, 50));
}

void Theme::initBack()
{
	font.loadFromFile("GAMERIA.ttf");
	textBack.setFont(font);
	textBack.setString("Powrot");
	rect = textBack.getGlobalBounds().getSize();
	textBack.setPosition(400 - rect.x / 2, 350);
}

void Theme::mainStyle()
{
	window->clear(sf::Color(85, 172, 238));
	window->draw(styleClassic);
	window->draw(styleWinter);
	window->draw(styleHell);
	window->draw(styleVoid);
	window->draw(textBack);
	window->display();
}
