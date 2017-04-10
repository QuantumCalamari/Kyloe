#include "keyHandler.h"
#include <iostream>

namespace Engine_2D {
	namespace input {

		void init(GLFWwindow* window) {
			glfwSetKeyCallback(window, key_callback);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (key == GLFW_KEY_W && action == GLFW_PRESS)
				std::cout << "W is pressed" << std::endl;
			if (key == GLFW_KEY_S && action == GLFW_PRESS)
				std::cout << "S is pressed" << std::endl;
			if (key == GLFW_KEY_A && action == GLFW_PRESS)
				std::cout << "A is pressed" << std::endl;
			if (key == GLFW_KEY_D && action == GLFW_PRESS)
				std::cout << "D is pressed" << std::endl;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
				std::cout << "Left Click" << std::endl;
			if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
				std::cout << "Right Click" << std::endl;
		}

		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			std::cout << "X pos: " << xpos << std::endl;
			std::cout << "Y pos: " << ypos << std::endl;

		}
	}
}