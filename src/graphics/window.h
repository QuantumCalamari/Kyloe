#pragma once

#include <iostream>
#include <GLFW\glfw3.h>
#include "../gameManager.h"

namespace Engine_2D {
	namespace graphics {

		class Window {
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;
		public:
			Window(const char *title, int width, int height, GameManager::Game game);
			~Window();
			bool closed() const;
			void update();
			void clear() const;
			bool up, down, left, right;
			void setUp();
		private:
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}