#pragma once
#include <GLFW\glfw3.h>

namespace Engine_2D {
	namespace input {
		class KeyHandler {
		public:
			void init(GLFWwindow* window);
		private:
			void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}