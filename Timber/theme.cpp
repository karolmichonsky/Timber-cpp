#include "Theme.h"

Theme::Theme(sf::RenderWindow* window, Game* game)
{

	this->window = window;
}

void Theme::initCheckBox(sf::RectangleShape* box, int boxXPos)
{
	box->setFillColor(sf::Color::White);
	box->setOutlineColor(sf::Color::Black);
	box->setPosition(boxXPos, 300);
	box->setSize(sf::Vector2f(50, 50));
}

void Theme::mainStyle()
{
	window->clear(sf::Color(85, 172, 238));
	window->display();
}
