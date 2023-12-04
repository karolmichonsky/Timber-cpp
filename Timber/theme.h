#pragma once
#include "Game.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
class Theme
{
private:
	Game* game;
	Menu* menu;

	sf::RenderWindow* window;
	sf::Event event;


	sf::RectangleShape styleClassic;
	sf::RectangleShape styleWinter;
	sf::RectangleShape styleHell;
	sf::RectangleShape styleVoid;

	sf::Text textBack;
	sf::Font font;
	sf::Vector2f rect;
	
	int checkboxPos;
	int themeMenuPos;
public:
	Theme(sf::RenderWindow* window, Game* game, Menu* menu);

	void pollEvents();

	void initCheckBox(sf::RectangleShape& box, int boxXPos, sf::Color boxColor);
	void initBack();
	void mainStyle();
};

