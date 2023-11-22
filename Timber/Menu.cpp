#include "Menu.h"

Menu::Menu(sf::RenderWindow* window) {
	this->window = window;
	this->initText();
}

Menu::~Menu() {
	//delete this->window;
}


void Menu::initText()
{
	this->font.loadFromFile("GAMERIA.ttf");
	textNewGame.setFont(font);
	textStyle.setFont(font);
	textLeaderboard.setFont(font);
	textLeave.setFont(font);
	this->textNewGame.setString("Nowa gra");
	this->textStyle.setString("Zmien skorke");
	this->textLeaderboard.setString("Tabela wynikow");
	this->textLeave.setString("Wyjdz z gry");
	rect = textNewGame.getGlobalBounds().getSize();
	textNewGame.setPosition(400 - rect.x / 2, 100);
	rect = textStyle.getGlobalBounds().getSize();
	textStyle.setPosition(400 - rect.x / 2, 200);
	rect = textLeaderboard.getGlobalBounds().getSize();
	textLeaderboard.setPosition(400 - rect.x / 2, 300);
	rect = textLeave.getGlobalBounds().getSize();
	textLeave.setPosition(400 - rect.x / 2, 400);
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
		}
	}
}

int Menu::accessGameState()
{
	return this->gameState;
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
