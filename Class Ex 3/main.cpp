#include "Point2D.h"
struct Point3D
{
	int mX;
	int mY;
	int mZ;
};
int main()
{
	Point2D First;
	First.SetCoordinate(0, 0);
	First.CalDistance(5, 5);
	First.PrintResult();

	Point3D pt2{ 1,1,1 };	// 모든 멤버가 public이기에 유니폼 초기화 가능
	
}
