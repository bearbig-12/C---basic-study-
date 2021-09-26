#include <iostream>
#include <cmath>
class Point2D
{
private:
	int mX;
	int mY;
public:
	Point2D() = default;
	Point2D(int x, int y) : mX{ x }, mY {y}{}
	~Point2D()
	{
	}

	int GetX()
	{
		return mX;
	}
	int GetY()
	{
		return mY;
	}
	void SetX(int x)
	{
		this->mX = x;
	}
	void SetY(int y)
	{
		this->mY = y;
	}
	void Print()
	{
		std::cout << "(" << mX << ", " << mY << ")" << std::endl;

	}
	operator double();
};

Point2D operator -(Point2D a, Point2D b)
{
	Point2D NewPt{ 0,0 };
	NewPt.SetX(a.GetX() - b.GetX());
	NewPt.SetY(a.GetY() - b.GetY());

	return NewPt;
	
}

Point2D operator --(Point2D& a)
{
	int x = a.GetX();
	int y = a.GetY();

	a.SetX(--x);
	a.SetY(--y);

	

	return a;

}

Point2D::operator double()
{
	return double(sqrt(pow(mX, 2) + pow(mY, 2)));
}

class MyArray
{
private:
	float* mArray;
public:
	MyArray() : mArray{} {}
	MyArray(int count)
	{
		mArray = new float[count];
	}
	~MyArray()
	{
		delete[] mArray;
	}

	float& operator [](int index)
	{
		return mArray[index];
	}
	// mArray[0] = 1; 값을 대입하기 위해서는 L-value 즉 객체를 받아와야 하기 때문에 int&를 사용해야 한다 만약 int값을 반환 할 경우 R_value이기에 값 대입 X
	operator const int();
};

MyArray::operator const int()
{
	return int(mArray);
}


int main()
{
	/*Point2D A{ 1, 2 }, B{ 3, 3 };
	Point2D C{ 0,0 };

	C = B - A;
	C.Print();

	--C;
	C.Print();

	double length = C;
	std::cout << C << std::endl;*/


	MyArray array(3);
	array[0] = 5.5f;
	array[1] = 10.5f;
	array[2] = 15.5f;

	std::cout << array[0] << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		int x = array[i];
		std::cout << array[i] << std::endl;
		std::cout << x << std::endl;
		
	}

}


