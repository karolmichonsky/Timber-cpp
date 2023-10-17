#include <iostream>
#include <cstdlib>
#include <vector>
#include <conio.h>
#include <ctime>
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

using namespace std;

void updateBranches(vector<int> branches) {
	srand(time(0));
	int random = (rand() % 3);
	branches.pop_back();
	branches.insert(branches.begin(), random);
}

void displayBranches(vector<int> branches) {
	system("cls");
	vector<int> branchesCopy;
	for (int i = 0; i < branches.size(); i++)
		branchesCopy.push_back(branches[i]);

	for (int i = 0; i < 5; i++) {
		if (branchesCopy[i] == 0) {
			cout << "--[   ]  " << endl;
		}
		else if (branchesCopy[i] == 1) {
			cout << "  [   ]--  " << endl;
		}
		else {
			cout << "  [   ]" << endl;
		}
	}
	
}

int main(void) {
	
	sf::Window window(sf::VideoMode(800, 600), "TimberTime");
	srand(time(0));
	vector<int> branches;
	
	for (int i = 0; i < 5; i++) {
		int random = (rand() % 3);
		branches.push_back(random);
	}
	displayBranches(branches);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				int random = (rand() % 3);
				if (event.key.code == sf::Keyboard::A) {
					if (branches[4] == 0) {
						window.close();
					}
					branches.pop_back();
					branches.insert(branches.begin(), random);
					displayBranches(branches);

				}
				else if (event.key.code == sf::Keyboard::D) {
					if (branches[4] == 1) {
						window.close();
					}
					branches.pop_back();
					branches.insert(branches.begin(), random);
					displayBranches(branches);
				}
			}		
		}
	}
	system("pause");
	return 0;
	}