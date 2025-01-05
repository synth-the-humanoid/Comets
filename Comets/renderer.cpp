#include "renderer.h"

Renderer::Renderer(HWND hWnd)
{
	if (D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory) == S_OK)
	{
		GetClientRect(hWnd, &windowRect);
		if (factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(windowRect.right - windowRect.left, windowRect.bottom - windowRect.top)), &renderTarget) == S_OK)
		{
			
		}
	}
	comets = new Comet*[1];
	comets[0] = NULL;
}

Renderer::~Renderer()
{
	if (renderTarget)
	{
		renderTarget->Release();
	}

	if (factory)
	{
		factory->Release();
	}

	delete comets;
}

void Renderer::AddComet(Comet* newComet)
{
	int currentSize = 0;
	while (comets[currentSize] != NULL)
	{
		currentSize++;
	}
	Comet** arrayClone = new Comet*[currentSize + 2];
	for (int i = 0; i < currentSize; i++)
	{
		arrayClone[i] = comets[i];
	}
	arrayClone[currentSize] = newComet;
	arrayClone[currentSize + 1] = NULL;
	delete comets;
	comets = arrayClone;
}

void Renderer::DrawFrame()
{
	GetClientRect(renderTarget->GetHwnd(), &windowRect);
	renderTarget->BeginDraw();
	//renderTarget->Clear(D2D1::ColorF(0, 0, 0));
	int i = 0;
	while (comets[i] != NULL)
	{
		DrawComet(comets[i++]);
	}
	renderTarget->EndDraw();
}

void Renderer::DrawComet(Comet* comet)
{
	ID2D1SolidColorBrush* brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(comet->r, comet->g, comet->b, comet->a), &brush);
	if (brush)
	{
		D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(comet->x, comet->y), comet->rad, comet->rad);
		renderTarget->DrawEllipse(ellipse, brush, 3);
		renderTarget->FillEllipse(ellipse, brush);
		brush->Release();
		comet->Advance();
		if (comet->x < 0 || comet->x >= windowRect.right - windowRect.left)
		{
			comet->xVel *= -1;
		}
		if (comet->y < 0 || comet->y >= windowRect.bottom - windowRect.top)
		{
			comet->yVel *= -1;
		}
		if (comet->rad >= 100 || comet->rad <=.5)
		{
			comet->radVel *= -1;
		}
	}
}