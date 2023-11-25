#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* window, Game* game) : game(game)
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
			cout << leaderboardHelper << " " << leaderboardPoints << endl;
			initText(leaderboardTop1, leaderboardPoints, 100);
			break;
		case 1:
			cout << leaderboardHelper << " " << leaderboardPoints << endl;
			initText(leaderboardTop2, leaderboardPoints, 200);
			break;
		case 2:
			initText(leaderboardTop3, leaderboardPoints, 300);
			break;
		}
		leaderboardHelper++;
	}

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
}

void Leaderboard::updateLeaderboard()
{
	readLeaderboard();
	window->clear(sf::Color(85, 172, 238));
	window->draw(leaderboardTop1);
	window->draw(leaderboardTop2);
	window->draw(leaderboardTop3);
	window->draw(leaderboardBackToMenu);
	window->display();

}
