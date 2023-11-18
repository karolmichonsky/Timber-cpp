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
    ofstream leaderboard;
    int gamePoints;

public:

    Leaderboard(int points);
    void saveLeaderboard();

};

