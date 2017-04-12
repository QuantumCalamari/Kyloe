#include "gameManager.h"
#include <iostream>

namespace Engine_2D {
	namespace GameManager {
		Game::Game() {

		}

		void Game::HandleKeyDown(){
			xPos += 0.01f;
			std::cout << "xPos: " << xPos << std::endl;
		}
	}
}