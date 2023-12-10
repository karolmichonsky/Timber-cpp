#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* window, Game* game, Menu* menu) : game(game), menu(menu)
{
	this->window = window;
	initNickname(nQ, "Q", 175, 300);
	initNickname(nW, "W", 225, 300);
	initNickname(nE, "E", 275, 300);
	initNickname(nR, "R", 325, 300);
	initNickname(nT, "T", 375, 300);
	initNickname(nY, "Y", 425, 300);
	initNickname(nU, "U", 475, 300);
	initNickname(nI, "I", 525, 300);
	initNickname(nO, "O", 575, 300);
	initNickname(nP, "P", 625, 300);
	initNickname(nA, "A", 200, 400);
	initNickname(nS, "S", 250, 400);
	initNickname(nD, "D", 300, 400);
	initNickname(nF, "F", 350, 400);
	initNickname(nG, "G", 400, 400);
	initNickname(nH, "H", 450, 400);
	initNickname(nJ, "K", 500, 400);
	initNickname(nK, "K", 550, 400);
	initNickname(nL, "L", 600, 400);
	initNickname(nZ, "Z", 250, 500);
	initNickname(nX, "X", 300, 500);
	initNickname(nC, "C", 350, 500);
	initNickname(nV, "V", 400, 500);
	initNickname(nB, "B", 450, 500);
	initNickname(nN, "N", 500, 500);
	initNickname(nM, "M", 550, 500);
	nicknameLetters.insert(nicknameLetters.end(), { nQ,nW,nE,nR,nT,nY,nU,nI,nO,nP,nA,nS,nD,
												   nF,nG,nH,nJ,nK,nL,nZ,nX,nC,nV,nB,nN,nM });
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
	leaderboardHelper = 0;
}

void Leaderboard::initText(sf::Text &textVar, string textValue, int textHeight)
{
	font.loadFromFile("GAMERIA.ttf");
	textVar.setFont(font);
	textVar.setString(textValue);
	rect = textVar.getGlobalBounds().getSize();
	textVar.setPosition(400 - rect.x / 2, textHeight);
}

void Leaderboard::initNickname(sf::Text& nicknameVar, string nicknameLetter, int nicknameWidth, int nicknameHeight)
{
	font.loadFromFile("GAMERIA.ttf");
	nicknameVar.setCharacterSize(30);
	nicknameVar.setFont(font);
	nicknameVar.setString(nicknameLetter);
	rect = nicknameVar.getGlobalBounds().getSize();
	nicknameVar.setPosition(nicknameWidth - rect.x / 2, nicknameHeight);
}

void Leaderboard::saveLeaderboard()
{
	checkRecord();
	leaderboardFileRead.open("leaderboard.txt");
	while (getline(leaderboardFileRead, leaderboardPoints)) {
		leaderboardIntPoints = stoi(leaderboardPoints);
		if (leaderboardPlace < 3) {
			leaderboardNewTop.push_back(leaderboardIntPoints);
		}
		else if(leaderboardPlace == 3){
			leaderboardNewTop.push_back(game->getGamePoints());
		}
		else {
			leaderboardNewTop.push_back(tempPoints);
		}
		tempPoints = leaderboardIntPoints;
		leaderboardPlace++;
	}
	leaderboardFileRead.close();
	leaderboardFileWrite.open("leaderboard.txt");
	leaderboardFileWrite << leaderboardNewTop[0] << "\n";
	leaderboardFileWrite << leaderboardNewTop[1] << "\n";
	leaderboardFileWrite << leaderboardNewTop[2];
	leaderboardFileWrite.close();
	leaderboardNewTop.clear();
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




