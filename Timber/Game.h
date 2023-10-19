#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

#include <iostream>
#include <cstdlib>
#include <vector>
#include <conio.h>
#include <ctime>
#include <time.h> 

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	sf::RectangleShape tree;

	void initVar();
	void initWindow();
	void initTree();
public:
	//Konstruktor i destruktor
	Game();
	virtual ~Game();

	const bool running() const;

	void displayBranches();
	void createBranches();
	void updateBranches();
	void pollEvents();
	void update();
	void render();
};

