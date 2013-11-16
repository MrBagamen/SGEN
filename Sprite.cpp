#include "Sprite.hpp"

sgen::Sprite::Sprite()
{
	w = 1;
	h = 1;
	x = y = 0;
}

void sgen::Sprite::Load(const char* fileName)
{
	SDL_Surface *img = IMG_Load(fileName);
	if(img == nullptr)
	{
		printf("%s\n", IMG_GetError());
		exit(1);
	}
	printf("Loaded %s\n", fileName);
	w = img->w;
	h = img->h;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, img->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(img);
	
	vertices[0] = -w/2; vertices[1] = -h/2;
	vertices[2] = w/2; vertices[3] = -h/2;
	vertices[4] = w/2; vertices[5] = h/2;
	vertices[6] = -w/2; vertices[7] = -h/2;
	vertices[8] = -w/2; vertices[9] = h/2;	
	vertices[10] = w/2; vertices[11] = h/2;
}

void sgen::Sprite::Draw()
{
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glTranslatef(x+w/2, y+h/2, 0.0f);
	//glRotatef(60, 0.0f, 0.0f, 1.0f);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glPopMatrix();
}

void sgen::Sprite::SetPosition(int _x, int _y)
{
	x = _x;
	y = _y;
}
