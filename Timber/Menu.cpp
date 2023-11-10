#include "Menu.h"

Menu::Menu() {
	/*this->initWindow();*/
	this->initButtonNewGame();
	this->initButtonExit();
	
}

Menu::~Menu() {
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
	while (win.window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::A) {
				gameState = 1;
			}
		}
	}
}

int Menu::accessGameState()
{
	return this->gameState;
}

void Menu::mainMenu()
{
	win.window->clear(sf::Color::Black);

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
}
