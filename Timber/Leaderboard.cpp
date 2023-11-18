#include "Leaderboard.h"

Leaderboard::Leaderboard(int points) : gamePoints(points)
{
	
}

void Leaderboard::saveLeaderboard()
{
	leaderboard.open("leaderboard.txt");
	leaderboard << gamePoints;
	leaderboard.close();
}
