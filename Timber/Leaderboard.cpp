#include "Leaderboard.h"

Leaderboard::Leaderboard(Game* game) : game(game)
{
	
}

void Leaderboard::saveLeaderboard()
{
	leaderboard.open("leaderboard.txt");
	leaderboard << game->getGamePoints();
	leaderboard.close();
}
