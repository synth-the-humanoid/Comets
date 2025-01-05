#ifndef COMET_RENDERER_H
#define COMET_RENDERER_H
#include <d2d1.h>
#include "comet.h"

class Renderer
{
	private:
		RECT windowRect;
		ID2D1Factory* factory;
		ID2D1HwndRenderTarget* renderTarget;
		Comet** comets;

		void DrawComet(Comet* comet);
	public:
		Renderer(HWND hWnd);
		~Renderer();
		void AddComet(Comet* newComet);
		void DrawFrame();
};



#endif