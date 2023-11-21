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


    ofstream leaderboardFileWrite;
    ifstream leaderboardFileRead;
    string leaderboardText;
public:

    Leaderboard(Game* game);
    void readLeaderboard();
    void saveLeaderboard();

};

