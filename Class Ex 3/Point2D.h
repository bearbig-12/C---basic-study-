#pragma once
#include <iostream>

class Point2D
{
private:
	int mX;
	int mY;
	double Distance;
	
public:
	// ������
	Point2D()
	{
		mX = mY = Distance = 0;
		std::cout << "������" << std::endl;
	}
	~Point2D()
	{
		std::cout << "�Ҹ���" << std::endl;
	}

public:
	void SetCoordinate(int x, int y);
	void PrintResult();
	double CalDistance(int x, int y);
};

