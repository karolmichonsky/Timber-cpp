#include "Menu.h"

Menu::Menu(sf::RenderWindow* window) {
	this->window = window;
	this->initButtonNewGame();
	this->initButtonExit();
	this->initText();
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

void Menu::initText()
{
	this->font.loadFromFile("GAMERIA.ttf");
	this->textNewGame.setFont(font);
	this->textNewGame.setPosition(300, 100);
	this->textStyle.setFont(font);
	this->textStyle.setPosition(300, 200);
	this->textLeave.setFont(font);
	this->textLeaderboard.setPosition(300, 300);
	this->textLeaderboard.setFont(font);
	this->textLeave.setPosition(300, 400);
	this->textNewGame.setString("Nowa gra");
	this->textStyle.setString("Zmien skorke");
	this->textLeaderboard.setString("Tabela wynikow");
	this->textLeave.setString("Wyjdz z gry");
}

void Menu::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

int Menu::accessGameState()
{
	return this->gameState;
}

void Menu::mainMenu()
{

}

void Menu::pauseGame()
{
}

void Menu::renderMenu()
{
}

void Menu::updateMenu()
{
	pollEvents();
	window->clear(sf::Color(85, 172, 238));
	window->draw(textNewGame);
	window->draw(textStyle);
	window->draw(textLeaderboard);
	window->draw(textLeave);
	window->display();
}
