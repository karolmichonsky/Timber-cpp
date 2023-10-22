#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

using namespace std;

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
	sf::VideoMode videoMode;
	sf::Event event;

	int points;
	float loseTimer;
	float loseTimerMax;
	int treeCounter;

	vector<sf::RectangleShape> trees;
	vector<int> helpBranches;
	vector<sf::RectangleShape> branches;
	sf::RectangleShape branchLeft;
	sf::RectangleShape branchRight;
	sf::RectangleShape branchHollow;
	sf::RectangleShape tree;

	void initVar();
	void initWindow();
	void initTree();
	void initBranchesLeft();
	void initBranchesRight();
	void initBranchesHollow();
public:
	//Konstruktor i destruktor
	Game();
	virtual ~Game();

	const bool running() const;
	
	
	void spawnBranches();
	void spawnTree();
	void pollEvents();
	void update();
	void updateTree();
	void render();
	void renderTree();
	void renderBranches();
};

