#include "Game.h"

void Game::initVar()
{
	this->window = nullptr;

	this->points = 0;
	this->loseTimerMax = 1000.f;
	this->loseTimer = this->loseTimerMax;
	this->gameOn = 0;
	this->isChopping = 0;
	this->isLeft = 0;

}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->videoMode.getDesktopMode;
	this->window = new sf::RenderWindow(this->videoMode, "TimberTime");
	this->window->setFramerateLimit(60);
}

void Game::initTree()
{
	this->tree.setPosition(300, 0);
	this->tree.setSize(sf::Vector2f(200, 100));
	this->tree.setFillColor(sf::Color(55, 29, 16));
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

Game::Game() {
	this->initVar();
	this->initWindow();
	this->initFloor();
	this->initTree();
	this->lumber();
	this->initBranchesHollow();
	this->initBranchesLeft();
	this->initBranchesRight();
}

Game::~Game() {
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::lumber()
{
	
	if (isChopping == 1) {
		textureLumberAway.loadFromFile("lumber-action-left.png");
	}
	else {
		textureLumberAway.loadFromFile("lumber-away-left.png");
	}
	sf::Sprite spriteLumberAway(textureLumberAway);
	spriteLumberAway.setPosition(200, 400);
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
					this->window->close();
				}
				this->treeHandle();
				isChopping = 1;
				
			}
			else if (event.key.code == sf::Keyboard::D) {
				if (this->helpLose[1] == 2) {
					this->window->close();
				}
				this->treeHandle();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				this->gameOn = 0;
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
		if (this->loseTimer == 0) {
			this->window->close();
		}
		else {
			this->loseTimer -= 1.f;
		}
	}
	

}

void Game::render()
{
	this->window->clear(sf::Color(85,172,238));

	this->update();

	this->window->draw(floor);
		
	this->renderTree();

	this->renderBranches();
	
	this->lumber();
	
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
