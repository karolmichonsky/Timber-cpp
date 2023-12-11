#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* window, Game* game, Menu* menu) : game(game), menu(menu)
{
	this->window = window;
	initNickname(nText, "Podaj nick na obecna sesje", 400, 50);
	initNickname(nQ, "Q", 175, 200);
	initNickname(nW, "W", 225, 200);
	initNickname(nE, "E", 275, 200);
	initNickname(nR, "R", 325, 200);
	initNickname(nT, "T", 375, 200);
	initNickname(nY, "Y", 425, 200);
	initNickname(nU, "U", 475, 200);
	initNickname(nI, "I", 525, 200);
	initNickname(nO, "O", 575, 200);
	initNickname(nP, "P", 625, 200);
	initNickname(nA, "A", 200, 300);
	initNickname(nS, "S", 250, 300);
	initNickname(nD, "D", 300, 300);
	initNickname(nF, "F", 350, 300);
	initNickname(nG, "G", 400, 300);
	initNickname(nH, "H", 450, 300);
	initNickname(nJ, "J", 500, 300);
	initNickname(nK, "K", 550, 300);
	initNickname(nL, "L", 600, 300);
	initNickname(nZ, "Z", 225, 400);
	initNickname(nX, "X", 275, 400);
	initNickname(nC, "C", 325, 400);
	initNickname(nV, "V", 375, 400);
	initNickname(nB, "B", 425, 400);
	initNickname(nN, "N", 475, 400);
	initNickname(nM, "M", 525, 400);
	initNickname(nDel, "<", 575, 400);
	initNickname(back, "Zapisz nick", 400, 500);
	nicknameLetters.insert(nicknameLetters.end(), { nQ,nW,nE,nR,nT,nY,nU,nI,nO,nP,nA,nS,nD,nF,nG
												   ,nH,nJ,nK,nL,nZ,nX,nC,nV,nB,nN,nM,nDel,back });
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

string Leaderboard::getNicknameGame()
{
	return nicknameGame;
}

void Leaderboard::updateNickname()
{
	window->clear(sf::Color(85, 172, 238));
	window->draw(nText);
	nicknameWIP = "lorem";
	initNickname(nNickname, nicknameWIP, 400, 150);
	window->draw(nNickname);
	for (auto& e : nicknameLetters) {
		window->draw(e);
	}
	window->display();
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




