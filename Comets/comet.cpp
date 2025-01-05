#include "comet.h"

Comet::Comet(float x, float y, float rad, float r, float g, float b, float a, float xVel, float yVel, float radVel)
{
	this->x = x;
	this->y = y;
	this->rad = rad;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	this->xVel = xVel;
	this->yVel = yVel;
	this->radVel = radVel;
}

Comet::Comet()
{
	this->x = rand() % 201;
	this->y = rand() % 201;
	this->rad = rand() % 21;
	this->r = (rand() % 101) / 100.0;
	this->g = (rand() % 101) / 100.0;
	this->b = (rand() % 101) / 100.0;
	this->a = (rand() % 101) / 100.0;
	this->xVel = rand() % 6;
	this->yVel = rand() % 6;
	this->radVel = (rand() % 30) / 100.0;
}

void Comet::Advance()
{
	x += xVel;
	y += yVel;
	rad += radVel;
}