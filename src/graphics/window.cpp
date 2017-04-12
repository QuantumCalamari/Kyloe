#include "window.h"

namespace Engine_2D {
	namespace graphics {

		Window::Window(const char *title, int width, int height, GameManager::Game game) {
			m_Title = title;
			m_Height = height;
			m_Width = width;
			if (!init()) {
				glfwTerminate();
			}

			glfwSetWindowUserPointer(m_Window, &game);

			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::init() {

			if (!glfwInit())
			{
				std::cout << "Failed to initialise GLFW" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window) {
				std::cout << "Failed to create GLFW Window" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);

			return true;
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void Window::update() {
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glViewport(0, 0, m_Width, m_Height);
			glfwSwapBuffers(m_Window);
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void init(GLFWwindow* window) {
			glfwSetKeyCallback(window, key_callback);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			GameManager::Game * game = reinterpret_cast<GameManager::Game *>(glfwGetWindowUserPointer(window));

			std::cout << "xPos when W: " << &game->xPos << std::endl;

			if (key == GLFW_KEY_W && action == GLFW_PRESS) {
				std::cout << "W is pressed" << std::endl;
				game->HandleKeyDown();
			}
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