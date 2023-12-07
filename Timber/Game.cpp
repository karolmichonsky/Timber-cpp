#include "Game.h"
#include "Leaderboard.h"

void Game::initVar()
{

	this->points = 0;
	this->loseTimerMax = 1000.f;
	this->loseTimer = 500.f;
	this->gameOn = 0;
	this->isChopping = 0;
	this->isLeft = 1;

}


void Game::initTree()
{
	this->tree.setPosition(300, 0);
	this->tree.setSize(sf::Vector2f(200, 100));
	this->tree.setFillColor(sf::Color(55, 29, 16));
}

void Game::initText()
{
	this->font.loadFromFile("GAMERIA.ttf");
	this->text.setFont(font);
	this->text.setPosition(400, 0);
	string stringPoints = to_string(points);
	this->text.setString(stringPoints);
}

void Game::initFloor()
{
	this->floor.setPosition(0, 400);
	this->floor.setSize(sf::Vector2f(800.f, 200.f));
	this->floor.setFillColor(sf::Color(0, 64, 0));
}

void Game::initBranchesLeft()
{
	this->branchLeft.setPosition(100, 0);
	this->branchLeft.setSize(sf::Vector2f(200.f, 10.f));
	this->branchLeft.setFillColor(sf::Color(55, 29, 16));;
}

void Game::initBranchesRight()
{
	this->branchRight.setPosition(500, 0);
	this->branchRight.setSize(sf::Vector2f(200.f, 10.f));
	this->branchRight.setFillColor(sf::Color(55, 29, 16));
}

void Game::initBranchesHollow()
{
	this->branchLeft.setSize(sf::Vector2f(0.f, 0.f));
}

void Game::initTimer()
{	
	this->timer.setPosition(300, 50);
	this->timer.setSize(sf::Vector2f(loseTimer/5, 15));
	this->timer.setFillColor(sf::Color::Red);
	this->timer.setOutlineColor(sf::Color(69,69,69));
	this->timer.setOutlineThickness(5.f);

}

Game::Game(sf::RenderWindow* window, Menu* menu) : window(window), menu(menu) {
	this->window = window;
	this->initVar();
	this->initText();
	this->initFloor();
	this->initTree();
	this->initTimer();
	this->lumber();
	this->initBranchesHollow();
	this->initBranchesLeft();
	this->initBranchesRight();
}

Game::~Game() {
	//delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::setIsChopping()
{
	isChopping = 1;
}

int Game::getIsChopping()
{
	return isChopping;
}

int Game::getGamePoints()
{
	return points;
}

void Game::resetGameStats()
{
	gameOn = 0;
	points = 0;
	loseTimer = 500.f;
	initText();
}

float Game::getLoseTimer()
{
	return loseTimer;
}

void Game::updatePoints()
{
	points++;
	if (points >= 10) {
		this->text.setPosition(390, 0);
	}
	string stringPoints = to_string(points);
	this->text.setString(stringPoints);
}

int Game::getGameOn()
{
	return gameOn;
}

void Game::setGameOn(int state)
{
	gameOn = state;
}

void Game::lumber()
{
	
	if (isChopping == 1 && isLeft == 1) {
		textureLumberAway.loadFromFile("lumber-action-left.png");
	}
	else if (isChopping == 1 && isLeft == 0) {
		textureLumberAway.loadFromFile("lumber-action-right.png");
	}
	else if (isChopping == 0 && isLeft == 1) {
		textureLumberAway.loadFromFile("lumber-away-left.png");
	}
	else if(isLeft == 0){
		textureLumberAway.loadFromFile("lumber-away-right.png");
	}
	sf::Sprite spriteLumberAway(textureLumberAway);
	if (isLeft == 1) {
		spriteLumberAway.setPosition(200, 400);
	}
	else {
		spriteLumberAway.setPosition(500, 400);
	}
	spriteLumberAway.setScale(1.5, 1.5);
	this->window->draw(spriteLumberAway);
}

void Game::lumberAnimation()
{
	sf::Clock clock;
	if (clock.getElapsedTime().asMilliseconds() > 1000 && isChopping == 1) {
		isChopping = 0;
		clock.restart();
	}
}

void Game::treeHandle()
{
	this->trees.erase(this->trees.begin());
	this->branches.erase(this->branches.begin());
	this->helpLose.erase(this->helpLose.begin());
	this->timeHandle();
}

void Game::timeHandle()
{
	this->gameOn = 1;
	this->loseTimer += 30.f;
	if (this->loseTimer > this->loseTimerMax) {
		this->loseTimer = this->loseTimerMax;
	}
}

void Game::spawnBranches()
{
	if (this->helpBranches.front() > 0) {
		if (helpBranches.front() == 1) {
			this->branches.push_back(this->branchLeft);
			this->helpBranches.erase(this->helpBranches.begin());
		}
		else{
			this->branches.push_back(this->branchRight);
			this->helpBranches.erase(this->helpBranches.begin());
		}
	}
	else{
		this->branches.push_back(this->branchHollow);
		this->helpBranches.erase(helpBranches.begin());
	}
}

void Game::resetTree()
{
	trees.clear();
	branches.clear();
	helpBranches.clear();
	helpLose.clear();
}

void Game::spawnTree()
{
	this->trees.push_back(this->tree);
}


void Game::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
		if (this->event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::A) {
				if (this->helpLose[1] == 1) {
					menu->setGameState(99);
				}
				else {
					this->updatePoints();
					this->treeHandle();
					isChopping = 1;
					isLeft = 1;
				}
				
			}
			else if (event.key.code == sf::Keyboard::D) {
				if (this->helpLose[1] == 2) {
					menu->setGameState(99);
				}
				else {
					this->treeHandle();
					this->updatePoints();
					isChopping = 1;
					isLeft = 0;
				}
				
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				menu->setGameState(99);
			}
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->gameUpdate();
}

void Game::gameUpdate()
{
	if (this->trees.size() == 0) {
		this->helpBranches.push_back(0);
		this->helpLose.push_back(0);
	}
	if (this->trees.size() < 5) {
		
		for (auto &e : this->trees) {
			e.move(0.f, 10.f);
			}
		for (auto& e : this->branches) {
			e.move(0.f, 10.f);
		}
		int random = (rand() % 3);
		this->helpBranches.push_back(random);
		this->helpLose.push_back(random);
		this->spawnTree();
		this->spawnBranches();
	}
	for (auto& e : this->trees) {
		sf::Vector2f pos = e.getPosition();
		if (fmod(pos.y, 100) != 0) {
			e.move(0.f, 9.f);
		}
	}
	for (auto& e : this->branches) {
		sf::Vector2f pos = e.getPosition();
		if (fmod(pos.y, 100) != 81) {
			e.move(0.f, 9.f);
		}
	}
	if (gameOn == 1) {
		this->loseTimer -= 1.f;
	}
	

}

void Game::render()
{
	this->window->clear(background);
	
	this->window->draw(floor);
	
	this->renderTree();

	this->renderBranches();
	
	this->window->draw(text);

	this->lumber();
	
	this->initTimer();
	this->window->draw(timer);
	
	this->window->display();
}

void Game::renderTree()
{
	for (auto &e : this->trees) {
		this->window->draw(e);
	}
}

void Game::renderBranches()
{
	for (auto& e : this->branches) {
		this->window->draw(e);
	}
}

void Game::setStyle(sf::Color styleTree, sf::Color styleFloor, sf::Color styleBackground)
{
	branchLeft.setFillColor(styleTree);
	branchRight.setFillColor(styleTree);
	floor.setFillColor(styleFloor);
	tree.setFillColor(styleTree);
	background = styleBackground;
}
