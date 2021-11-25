#pragma once

#include "D2DFramWork.h"
class Actor
{
protected:
	D2DFramWork* mpFramework;
	ID2D1Bitmap* mpBitmap;

	float mX;
	float mY;
	float mOpacity;

public:
	Actor() = delete;
	Actor(D2DFramWork* pFramework, LPCWSTR filename);
	Actor(D2DFramWork* pFramework, LPCWSTR filename,
		float x, float y, float opacity = 1.0f);
	virtual  ~Actor();

private:
	void Draw(float x, float y, float opacity = 1.0f);

public:
	virtual void Draw();
	void SetPosition(float x, float y) { mX = x, mY = y; }
	void SetOpacity(float o) { mOpacity = o; }


};

