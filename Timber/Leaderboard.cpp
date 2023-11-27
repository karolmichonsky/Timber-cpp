#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* window, Game* game, Menu* menu) : game(game), menu(menu)
{
	this->window = window;
}

void Leaderboard::readLeaderboard()
{
	
	leaderboardFileRead.open("leaderboard.txt");
	int leaderboardHelper = 0;
	while (getline(leaderboardFileRead, leaderboardPoints)) {
		switch (leaderboardHelper) {
		case 0:
			initText(leaderboardTop1, leaderboardPoints, 200);
			break;
		case 1:
			initText(leaderboardTop2, leaderboardPoints, 300);
			break;
		case 2:
			initText(leaderboardTop3, leaderboardPoints, 400);
			break;
		}
		leaderboardHelper++;
	}
	initText(leaderboardText, "Top 3 wyniki graczy", 100);
	initText(leaderboardBackToMenu, "Powrot", 500);
	leaderboardBackToMenu.setFillColor(sf::Color::Red);

	leaderboardFileRead.close();
}

void Leaderboard::initText(sf::Text &textVar, string textValue, int textHeight)
{
	font.loadFromFile("GAMERIA.ttf");
	textVar.setFont(font);
	textVar.setString(textValue);
	rect = textVar.getGlobalBounds().getSize();
	textVar.setPosition(400 - rect.x / 2, textHeight);
}

void Leaderboard::saveLeaderboard()
{
	leaderboardFileWrite.open("leaderboard.txt");
	leaderboardFileWrite << game->getGamePoints();
	leaderboardFileWrite << game->getGamePoints();
	leaderboardFileWrite << game->getGamePoints();
	leaderboardFileWrite.close();
}

void Leaderboard::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Enter) {
				menu->backToMenu();
			}
			if (event.key.code == sf::Keyboard::Escape) {
				menu->backToMenu();
			}
		}
	}
}

void Leaderboard::updateLeaderboard()
{
	pollEvents();
	readLeaderboard();
	window->clear(sf::Color(85, 172, 238));
	window->draw(leaderboardText);
	window->draw(leaderboardTop1);
	window->draw(leaderboardTop2);
	window->draw(leaderboardTop3);
	window->draw(leaderboardBackToMenu);
	window->display();

}


