#include "Game.h"

void Game::initVar()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->videoMode.getDesktopMode;
	this->window = new sf::RenderWindow(this->videoMode, "TimberTime");
}

Game::Game() {
	this->initVar();
	this->initWindow();
}

Game::~Game() {
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::displayBranches()
{
	/*system("cls");
	vector<int> branchesCopy;
	for (int i = 0; i < branches.size(); i++)
		branchesCopy.push_back(branches[i]);

	for (int i = 0; i < 5; i++) {
		if (branchesCopy[i] == 0) {
			cout << "--[   ]  " << endl;
		}
		else if (branchesCopy[i] == 1) {
			cout << "  [   ]--  " << endl;
		}
		else {
			cout << "  [   ]" << endl;
		}
	}*/
}

void Game::createBranches()
{
	/*srand(time(0));
	for (int i = 0; i < 5; i++) {
		int random = (rand() % 3);
		branches.push_back(random);
	}
	displayBranches(branches);*/
}

void Game::updateBranches()
{
	/*srand(time(0));
	int random = (rand() % 3);
	branches.pop_back();
	branches.insert(branches.begin(), random);*/
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
		if (this->event.type == sf::Event::KeyPressed) {
			int random = (rand() % 3);
			if (event.key.code == sf::Keyboard::A) {
				/*if (branches[4] == 0) {
					this->window->close();
				}
				branches.pop_back();
				branches.insert(branches.begin(), random);
				displayBranches(branches);*/

			}
			else if (event.key.code == sf::Keyboard::D) {
				/*if (branches[4] == 1) {
					this->window->close();
				}
				branches.pop_back();
				branches.insert(branches.begin(), random);
				displayBranches(branches);*/
			}
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear(sf::Color(85,172,238));

	this->window->display();
}
