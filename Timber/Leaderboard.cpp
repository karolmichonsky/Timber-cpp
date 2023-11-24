#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* window, Game* game) : game(game)
{
	this->window = window;
	initText();
}

void Leaderboard::readLeaderboard()
{
	
	leaderboardFileRead.open("leaderboard.txt");
	int a = 100;
	while (getline(leaderboardFileRead, leaderboardPoints)) {
		font.loadFromFile("GAMERIA.ttf");
		leaderboardTop1.setFont(font);
		leaderboardTop1.setString(leaderboardPoints);
		rect = leaderboardTop1.getGlobalBounds().getSize();
		leaderboardTop1.setPosition(400 - rect.x / 2, a);
		rect = leaderboardTop1.getGlobalBounds().getSize();
		a += 100;
		window->draw(leaderboardTop1);
	}

	leaderboardFileRead.close();
}

void Leaderboard::initText()
{
	font.loadFromFile("GAMERIA.ttf");

	leaderboardBackToMenu.setFont(font);
	leaderboardBackToMenu.setString("Powrot");
	rect = leaderboardBackToMenu.getGlobalBounds().getSize();
	leaderboardBackToMenu.setPosition(400 - rect.x / 2, 400);
	rect = leaderboardBackToMenu.getGlobalBounds().getSize();
	
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
	cout << leaderboardPoints;
	window->draw(leaderboardTop1);
	window->draw(leaderboardBackToMenu);
	window->display();

}
