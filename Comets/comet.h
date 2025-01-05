#ifndef COMET_COMET_H
#define COMET_COMET_H
#include <random>

class Comet
{
	public:
		float xVel;
		float yVel;
		float radVel;
		float x;
		float y;
		float r;
		float g;
		float b;
		float a;
		float rad;

		Comet();
		Comet(float x, float y, float rad, float r, float g, float b, float a, float xVel, float yVel, float radVel);
		void Advance();
};

#endif