#include "Game.h"

void Game::initVar()
{
	this->window = nullptr;

	this->points = 0;
	this->loseTimerMax = 1000.f;
	this->loseTimer = this->loseTimerMax;

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
	this->tree.setSize(sf::Vector2f(200.f, 100.f));
	this->tree.setFillColor(sf::Color(55, 29, 16));
	this->tree.setOutlineColor(sf::Color(95, 69, 56));
	this->tree.setOutlineThickness(1.f);

}

Game::Game() {
	this->initVar();
	this->initWindow();
	this->initTree();
}

Game::~Game() {
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
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
				this->trees.erase(this->trees.begin());
			}
			else if (event.key.code == sf::Keyboard::D) {
				this->trees.erase(this->trees.begin());
			}
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->updateTree();
}

void Game::updateTree()
{
	if (this->trees.size() < 5) {
		for (auto &e : this->trees) {
			e.move(0.f, 100.f);
			}
		this->spawnTree();
	}
	
	if (this->loseTimer == 0) {
		this->window->close();
	}
	else {
		this->loseTimer -= 1.f;
	}

}

void Game::render()
{
	this->window->clear(sf::Color(85,172,238));

	this->update();
		
	this->renderTree();

	this->window->display();
}

void Game::renderTree()
{
	for (auto &e : this->trees) {
		this->window->draw(e);
	}
}
