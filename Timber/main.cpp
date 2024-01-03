#include "Game.h"
#include "Menu.h"
#include "Leaderboard.h"
#include "Theme.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int WinMain(void) {
	
	srand(static_cast<unsigned>(time(NULL)));	

	
	sf::VideoMode vm(800, 600);
	sf::RenderWindow window(vm, "Timber");
	window.setFramerateLimit(60);

	Menu menu(&window);
	Game game(&window, &menu);
	Leaderboard leaderboard(&window, &game, &menu);
	Theme theme(&window, &game, &menu);
	sf::Clock clock;
	game.setSavedGame();

	while (game.running()) {
		switch(menu.accessGameState()){
			case -1:
				menu.updateMenu();
				break;
			case 0:
				if (leaderboard.getNicknameGame()==""){
					leaderboard.updateNickname();
				}
				else if (leaderboard.getNicknameGame() != "" && game.getSavedGame() == 1) {
					game.manageSavedGame();
				}
				else {
					if (game.getLoseTimer() < 0.0f) {
						menu.setGameState(99);
					}
					game.update();
					if (clock.getElapsedTime().asMilliseconds() > 2000 && game.getIsChopping() == 1) {
						game.setIsChopping();
						clock.restart();
					}
					game.lumberAnimation();
					game.render();
					}
				break;
			case 1:
				theme.mainStyle();
				break;
			case 2:
				leaderboard.updateLeaderboard();
				break;
			case 3:
				window.close();
				break;
			case 99:
				leaderboard.saveLeaderboard();
				game.resetGameStats();
				game.resetSave();
				game.resetTree();
				menu.backToMenu();
		}
	}
	return 0;
}