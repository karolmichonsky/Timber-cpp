#include "Leaderboard.h"

Leaderboard::Leaderboard(Game* game) : game(game)
{
	
}

void Leaderboard::readLeaderboard()
{
	
	leaderboardFileRead.open("leaderboard.txt");

	while (getline(leaderboardFileRead, leaderboardText)) {
		cout << leaderboardText;
	}

	leaderboardFileRead.close();
}

void Leaderboard::saveLeaderboard()
{
	leaderboardFileWrite.open("leaderboard.txt");
	leaderboardFileWrite << game->getGamePoints();
	leaderboardFileWrite.close();
}
