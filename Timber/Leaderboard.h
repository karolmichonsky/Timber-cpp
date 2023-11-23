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
    sf::RenderWindow* window;
    sf::Event event;

    sf::Text leaderboardTop1;
    sf::Text leaderboardBackToMenu;
    sf::Font font;
    sf::Vector2f rect;

    ofstream leaderboardFileWrite;
    ifstream leaderboardFileRead;
    string leaderboardPoints;
public:

    Leaderboard(sf::RenderWindow* window, Game* game);
    void pollEvents();
    void initText();
    void readLeaderboard();
    void saveLeaderboard();

    void updateLeaderboard();

};

