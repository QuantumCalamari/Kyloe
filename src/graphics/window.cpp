#include "window.h"

namespace Engine_2D {
	namespace graphics {

		Window::Window(const char *title, int width, int height) {
			m_Title = title;
			m_Height = height;
			m_Width = width;
			if (!init()) {
				glfwTerminate();
			}
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
	}
}