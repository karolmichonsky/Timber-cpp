#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

using namespace std;

#include <iostream>

class Menu
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	sf::RectangleShape buttonNewGame;
	sf::RectangleShape buttonExit;
	sf::RectangleShape buttonResume;
	
	int gameState = 1;
	void initButtonNewGame();
	void initButtonExit();
public:
	Menu(sf::RenderWindow* window);
	virtual ~Menu();

	void pollEvents();
	int accessGameState();
	void mainMenu();
	void pauseGame();
	void renderMenu();
	void updateMenu();
};

