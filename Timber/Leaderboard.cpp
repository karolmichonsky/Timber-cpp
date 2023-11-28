#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* window, Game* game, Menu* menu) : game(game), menu(menu)
{
	this->window = window;
}

void Leaderboard::readLeaderboard()
{
	
	leaderboardFileRead.open("leaderboard.txt");
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
	checkRecord();
	leaderboardFileRead.open("leaderboard.txt");
	while (getline(leaderboardFileRead, leaderboardPoints)) {
		leaderboardIntPoints = stoi(leaderboardPoints);
		cout << leaderboardPlace << endl;
		if (leaderboardPlace < 2) {
			leaderboardNewTop.push_back(leaderboardIntPoints);
		}
		else if(leaderboardPlace == 2){
			leaderboardNewTop.push_back(game->getGamePoints());
		}
		else {
			leaderboardNewTop.push_back(tempPoints);
		}
		tempPoints = leaderboardIntPoints;
		leaderboardPlace++;
	}
	leaderboardFileRead.close();
	leaderboardPlace = 0;
}

void Leaderboard::checkRecord()
{
	leaderboardFileRead.open("leaderboard.txt");
	while (getline(leaderboardFileRead, leaderboardPoints)) {
		leaderboardIntPoints = stoi(leaderboardPoints);
		if (game->getGamePoints() > leaderboardIntPoints) {
			leaderboardPlace++;
		}
	}
	leaderboardFileRead.close();
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




