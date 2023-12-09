#include "Menu.h"

Menu::Menu(sf::RenderWindow* window) {
	this->window = window;
	initText(textNewGame, "Nowa gra", 100);
	initText(textStyle, "Zmien motyw", 200);
	initText(textLeaderboard, "Tabela wynikow", 300);
	initText(textLeave, "Wyjdz z gry", 400);
}

Menu::~Menu() {
	//delete this->window;
}


void Menu::initText(sf::Text& textVar, string textValue, int textHeight)
{
	font.loadFromFile("GAMERIA.ttf");
	textVar.setFont(font);
	textVar.setString(textValue);
	rect = textVar.getGlobalBounds().getSize();
	textVar.setPosition(400 - rect.x / 2, textHeight);
}



void Menu::selectedMenu()
{
	switch (menuState) {
	case 0:
		textLeave.setFillColor(sf::Color::White);
		textNewGame.setFillColor(sf::Color::Red);
		textStyle.setFillColor(sf::Color::White);
		break;
	case 1:
		textNewGame.setFillColor(sf::Color::White);
		textStyle.setFillColor(sf::Color::Red);
		textLeaderboard.setFillColor(sf::Color::White);
		break;
	case 2:
		textStyle.setFillColor(sf::Color::White);
		textLeaderboard.setFillColor(sf::Color::Red);
		textLeave.setFillColor(sf::Color::White);
		break;
	case 3:
		textLeaderboard.setFillColor(sf::Color::White);
		textLeave.setFillColor(sf::Color::Red);
		textNewGame.setFillColor(sf::Color::White);
		break;
	}
}

void Menu::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
		if (this->event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::S) {
				menuState += 1;
				if (menuState > 3) {
					menuState =0;
				}
			}
			if (event.key.code == sf::Keyboard::W) {
				menuState -= 1;
				if (menuState < 0) {
					menuState = 3;
				}
			}
			if (event.key.code == sf::Keyboard::Enter) {
				gameState = menuState;
			}
			if (event.key.code == sf::Keyboard::Escape) {
				window->close();
			}
		}
	}
}

int Menu::accessGameState()
{
	return this->gameState;
}

void Menu::setGameState(int state)
{
	gameState = state;
}

void Menu::backToMenu()
{
	gameState = -1;
}


void Menu::updateMenu()
{
	selectedMenu();
	pollEvents();
	window->clear(sf::Color(85, 172, 238));
	window->draw(textNewGame);
	window->draw(textStyle);
	window->draw(textLeaderboard);
	window->draw(textLeave);
	window->display();
}
