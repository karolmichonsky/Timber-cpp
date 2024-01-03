#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

using namespace std;

#include "Menu.h"

#include <vector>
#include <iostream>
#include <fstream>
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
	int savedGame;

	sf::Font font;
	sf::Text text;
	sf::Text pauseResume;
	sf::Text pauseEscape;

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
	sf::Color background = sf::Color(85, 172, 238);
	sf::Texture textureLumberAway;
	sf::Sprite spriteLumberAway;
	sf::Texture textureLumberAction;
	sf::Sprite spriteLumberAction;

	ofstream lastGameStatusWrite;
	ifstream lastGameStatusRead;
	string lastGameLine;
	int lastGamePos = 0;
	sf::Text savedGameText1;
	sf::Text savedGameText2;
	sf::Text savedGameNewGame;
	sf::Text savedGameContinue;
	int savedGamePos = 0;

	void initText();
	void initVar();
	void initFloor();
	void initTree();
	void initBranchesLeft();
	void initBranchesRight();
	void initBranchesHollow();
	void initTimer();
	void initPauseResume();
	void initPauseEscape();
	void initSavedGame();
	void initSavedGamePos();

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
	void checkSave();
	void setSave();
	void resetSave();
	int getSavedGame();
	void setSavedGame();
	void manageSavedGame();
	void pollEventsSavedGame();

	void setStyle(sf::Color styleTree, sf::Color styleFloor, sf::Color styleBackground);
};

