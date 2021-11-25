#pragma once
#include "Actor.h"
class Bug :
    public Actor
{

    int mSteps;
    float mRotation{};
    const D2D_POINT_2F UPVECTOR{ 0.0f,-1.0f };
    bool mIsDelete{};
public:
    Bug(D2DFramWork* pFramework);

    virtual void Draw() override;

    bool isClicked(POINT& pt);
};

