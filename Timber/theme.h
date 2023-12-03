#pragma once
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
class Theme
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	Game* game;

	sf::RectangleShape styleClassic;
	sf::RectangleShape styleWinter;
	sf::RectangleShape styleHell;
	sf::RectangleShape styleVoid;

	sf::Text textBack;
	sf::Font font;
	sf::Vector2f rect;
public:
	Theme(sf::RenderWindow* window, Game* game);

	void initCheckBox(sf::RectangleShape& box, int boxXPos, sf::Color boxColor);
	void initBack();
	void mainStyle();
};

