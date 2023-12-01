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
public:
	Theme(sf::RenderWindow* window, Game* game);

	void initCheckBox(sf::RectangleShape* box, int boxXPos);
	void mainStyle();
};

