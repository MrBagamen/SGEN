#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include "sgenMain.hpp"

namespace sgen
{
	class Sprite
	{
		public:
			void Load(const char* fileName);
			void Draw();
			Sprite();
			void SetPosition(int _x, int _y);
		private:
			GLuint texture;
			int x, y, w, h;
			GLfloat vertices[12];
			GLfloat texcoords[12] = {0.0f, 0.0f,
									1.0f, 0.0f,
									1.0f, 1.0f,
									0.0f, 0.0f,
									0.0f, 1.0f,
									1.0f, 1.0f
									};
	};
}

#endif
