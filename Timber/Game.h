#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

using namespace std;

#include "Menu.h"

#include <vector>
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
	sf::Event event;

	Menu* menu;

	int isChopping;
	int points;
	int gameOn;
	float loseTimer;
	float loseTimerMax;
	int treeCounter;
	int isLeft;

	sf::Font font;
	sf::Text text;

	vector<sf::RectangleShape> trees;
	vector<int> helpBranches;
	vector<int> helpLose;
	vector<sf::RectangleShape> branches;

	sf::RectangleShape timer;
	sf::RectangleShape branchLeft;
	sf::RectangleShape branchRight;
	sf::RectangleShape branchHollow;
	sf::RectangleShape tree;
	sf::RectangleShape floor;
	sf::Texture textureLumberAway;
	sf::Sprite spriteLumberAway;
	sf::Texture textureLumberAction;
	sf::Sprite spriteLumberAction;

	void initText();
	void initVar();
	void initFloor();
	void initTree();
	void initBranchesLeft();
	void initBranchesRight();
	void initBranchesHollow();
	void initTimer();
public:
	//Konstruktor i destruktor
	Game(sf::RenderWindow* window, Menu* menu);

	virtual ~Game();

	const bool running() const;
	void setIsChopping();
	int getIsChopping();
	int getGamePoints();
	void resetGameStats();
	float getLoseTimer();
	void updatePoints();
	int getGameOn();
	void setGameOn(int state);
	void lumber();
	void lumberAnimation();
	void treeHandle();
	void timeHandle();
	void spawnBranches();
	void resetTree();
	void spawnTree();
	void pollEvents();
	void update();
	void gameUpdate();
	void render();
	void renderTree();
	void renderBranches();
};

