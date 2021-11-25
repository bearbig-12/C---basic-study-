#pragma once
#include "D2DFramWork.h"
#include <memory>
#include <list>
#include "Actor.h"
#include "Bug.h"
//임의의 위치에 벌레 40마리를 그립시다.
// 컨테이너 : 아무곳에서 삭제 삽입
// list
// pointer vs smart-pointer
class BuggyHouse :
    public D2DFramWork
{
    std::unique_ptr<Actor> mspBackground;
    std::list<std::unique_ptr<Bug>> mBuglist;

public:
    virtual HRESULT Initialize(
        HINSTANCE hInstance, LPCWSTR title = L"Buggy House", 
        UINT width = 1024, UINT height = 768
    ) override;
    virtual void Release() override;
    virtual void Render() override;

    void CheckBugs();
};


