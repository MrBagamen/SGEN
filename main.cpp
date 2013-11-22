#include "sgenMain.hpp"
#include "Sprite.hpp"

int main(int argc, char *argv[])
{
	sgen::Main m;
	m.Create("ShitEngine", 800, 600);	
	sgen::Sprite spr;
	spr.Load("res/shit.png");
	spr.SetPosition(0, 0);
	
	while(m.isRunning())
	{
		spr.Draw();
		
		m.update();
	}
	
	return m.quit();
}
