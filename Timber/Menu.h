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

	vector<sf::Text> textArray;
	sf::Vector2f rect;
	
	int menuState = 0;
	int gameState = -1;
	void initText(sf::Text& textVar, string textValue, int textHeight);
public:
	Menu(sf::RenderWindow* window);
	virtual ~Menu();

	void selectedMenu();
	void pollEvents();
	int accessGameState();
	void setGameState(int state);
	void backToMenu();
	void updateMenu();
};

