#include "Point2D.h"
#include <iostream>
#include <cmath>
void Point2D::SetCoordinate(int x, int y)
{
	this->mX = x;
	this->mY = y;
}

double Point2D::CalDistance(int x, int y)
{
	int xDistance = mX - x;
	int yDistance = mY - y;

	Distance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));
	return Distance;
}
void Point2D::PrintResult()
{
	
	std::cout << "(" << mX << " , " << mY << ")" << std::endl;
	std::cout << "Distance = " << this->Distance << std::endl;
}

