#include "Menu.h"

Menu::Menu(sf::RenderWindow* window) {
	this->window = window;
	this->initButtonNewGame();
	this->initButtonExit();
}

Menu::~Menu() {
	//delete this->window;
}

void Menu::initButtonNewGame()
{
	this->buttonNewGame.setPosition(200, 300);
	this->buttonNewGame.setSize(sf::Vector2f(400, 200));
	this->buttonNewGame.setFillColor(sf::Color::Green);
	this->buttonNewGame.setOutlineColor(sf::Color::Black);
}

void Menu::initButtonExit()
{
	this->buttonNewGame.setPosition(200, 300);
	this->buttonNewGame.setSize(sf::Vector2f(400, 200));
	this->buttonNewGame.setFillColor(sf::Color::Green);
	this->buttonNewGame.setOutlineColor(sf::Color::Black);
}

void Menu::pollEvents()
{
	
}

int Menu::accessGameState()
{
	return this->gameState;
}

void Menu::mainMenu()
{
	window->draw(buttonExit);

}

void Menu::pauseGame()
{
}

void Menu::renderMenu()
{
}

void Menu::updateMenu()
{
	
	this->pollEvents();
	mainMenu();
}
