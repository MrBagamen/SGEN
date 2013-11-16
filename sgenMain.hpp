#ifndef SGENMAIN_HPP_INCLUDED
#define SGENMAIN_HPP_INCLUDED

#include <cstdio>
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

namespace sgen
{
	class Main
	{
		public:
			int w, h;
			void Create(const char* title, int _w, int _h);
			bool isRunning();
			void update();
			int quit();
		private:
			SDL_Window *win;
			SDL_GLContext glc;
			SDL_Event event;
			
			void InitEverything();
	};
}

#endif
