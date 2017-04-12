#include <iostream>
#include <GLFW\glfw3.h>

#include "src\graphics\window.h"
#include "src\gameManager.h"

int main() {

	using namespace Engine_2D;
	using namespace graphics;

	GameManager::Game game;
	Window window("test", 800, 600, game);

	std::cout << "xPos in main: " << &game.xPos << std::endl;

	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);

	while (!window.closed()) {
		glClear(GL_COLOR_BUFFER_BIT);
		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(game.xPos, game.yPos);
		glVertex2f(game.xPos - game.xLen, game.yPos);
		glVertex2f(game.xPos - game.xLen, game.yPos - game.yLen);
		glVertex2f(game.xPos, game.yPos - game.yLen);
		glEnd();
		window.update();

		//std::cout << "xPos: " << game.xPos << std::endl;
	}

	system("PAUSE");
	return 0;
}