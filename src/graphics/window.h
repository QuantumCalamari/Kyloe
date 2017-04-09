#pragma once

#include <iostream>
#include <GLFW\glfw3.h>

namespace Engine_2D {
	namespace graphics {

		class Window {
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;
		public:
			Window(const char *title, int width, int height);
			~Window();
			bool closed() const;
			void update();
			void clear() const;
			bool up, down, left, right;
			void setUp();
		private:
			bool init();
		};
	}
}