#pragma once

#include "Game.h"

#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

using namespace std;

class Leaderboard
{
private:

    Game* game;
	Menu* menu;
    sf::RenderWindow* window;
    sf::Event event;

    sf::Text leaderboardTop1;
    sf::Text leaderboardTop2;
    sf::Text leaderboardTop3;
    sf::Text leaderboardBackToMenu;
    sf::Text leaderboardText;
    sf::Font font;
    sf::Vector2f rect;


	sf::Text nQ;
	sf::Text nW;
	sf::Text nE;
	sf::Text nR;
	sf::Text nT;
	sf::Text nY;
	sf::Text nU;
	sf::Text nI;
	sf::Text nO;
	sf::Text nP;
	sf::Text nA;
	sf::Text nS;
	sf::Text nD;
	sf::Text nF;
	sf::Text nG;
	sf::Text nH;
	sf::Text nJ;
	sf::Text nK;
	sf::Text nL;
	sf::Text nZ;
	sf::Text nX;
	sf::Text nC;
	sf::Text nV;
	sf::Text nB;
	sf::Text nN;
	sf::Text nM;
	vector<sf::Text> nicknameLetters;

    vector<int> leaderboardNewTop;

    ofstream leaderboardFileWrite;
    ifstream leaderboardFileRead;
    string leaderboardPoints;

    int leaderboardPlace;
    int leaderboardIntPoints = 0;
    int leaderboardHelper = 0;
    int tempPoints;
	void initNickname(sf::Text& nicknameVar, string nicknameLetter, int nicknameWidth, int nicknameHeight);
	void initText(sf::Text& textVar, string textValue, int textHeight);
public:

    Leaderboard(sf::RenderWindow* window, Game* game, Menu* menu);
    void pollEvents();
    void readLeaderboard();
    void saveLeaderboard();
    void checkRecord();

    void updateLeaderboard();

};

