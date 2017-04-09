#include <iostream>
#include <GLFW\glfw3.h>

#include "src\graphics\window.h"
#include "src\input\keyHandler.h"

int main() {

	using namespace Engine_2D;
	using namespace graphics;

	Window window("test", 800, 600);

	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);

	while (!window.closed()) {
		glClear(GL_COLOR_BUFFER_BIT);
		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
		window.update();
	}

	system("PAUSE");
	return 0;
}