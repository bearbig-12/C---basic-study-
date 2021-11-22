#pragma once

#include "D2DFramWork.h"
class Actor
{
protected:
	D2DFramWork* mpFramework;
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap;

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
	HRESULT LoadWICImage(LPCWSTR filename);
	void Draw(float x, float y, float opacity = 1.0f);

public:
	virtual void Draw();
	void SetPosition(float x, float y) { mX = x, mY = y; }
	void SetOpacity(float o) { mOpacity = o; }


};

