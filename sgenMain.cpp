#include "sgenMain.hpp"

void sgen::Main::Create(const char* title, int _w, int _h)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("%s\n", SDL_GetError());
		exit(1);
	}
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted=IMG_Init(flags);
	if(initted&flags != flags)
	{
		printf("%s\n", IMG_GetError());
		exit(1);
	}
	
	w = _w;
	h = _h;
	win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _w, _h, SDL_WINDOW_OPENGL);
	glc = SDL_GL_CreateContext(win);
	
	InitEverything();
}

void sgen::Main::InitEverything()
{
	GLenum err = glewInit();
	if(GLEW_OK != err)
	{
		printf("Failed to initialize GLEW!\n");
		exit(1);
	}
	//printf("Using GLEW: %s\n", glewGetString(GLEW_VERSION));
	if(glewIsSupported("GL_VERSION_2_1"))
	{
		printf("OpenGL 2.1 Available\n");
	}
	else
	{
		printf("OpenGL 2.1 not supported\n");
		exit(1);
	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, h, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glEnable(GL_TEXTURE_2D);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glDisable(GL_DEPTH_TEST);
}

bool sgen::Main::isRunning()
{
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				return false;
				break;
			default:;
		}
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	return true;
}

int sgen::Main::quit()
{
	SDL_GL_DeleteContext(glc);
	SDL_Quit();
	return 0;
}

void sgen::Main::update()
{
	SDL_GL_SwapWindow(win);
}
