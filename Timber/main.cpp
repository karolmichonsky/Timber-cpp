#include "Game.h"

int main(void) {
	
	srand(static_cast<unsigned>(time(NULL)));	

	Game game;
	
	while (game.running()) {
		
		game.update();

		game.render();
	}
	return 0;
}