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

	sf::Font font;
	sf::Text textNewGame;
	sf::Text textStyle;
	sf::Text textLeaderboard;
	sf::Text textLeave;

	sf::RectangleShape buttonNewGame;
	sf::RectangleShape buttonExit;
	sf::RectangleShape buttonResume;
	
	int gameState = 0;
	void initButtonNewGame();
	void initButtonExit();
	void initText();
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

