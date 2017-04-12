#pragma once

namespace Engine_2D {
	namespace GameManager {
		class Game {
		public:
			Game();
			double xPos = 0.1f, yPos = 0.1f;
			double xLen = 0.2f, yLen = 0.2f;
			void HandleKeyDown();
		};
	}
}