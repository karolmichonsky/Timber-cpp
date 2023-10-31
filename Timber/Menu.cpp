#include "Menu.h"

int Menu::accessGameState()
{
	return this->gameState;
}

void Menu::mainMenu()
{
	this->window->clear(sf::Color::Black);
}

void Menu::pauseGame()
{
}
