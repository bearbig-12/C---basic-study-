#include <iostream>
#include <cmath>
class Point2D
{
private:
	int mX;
	int mY;
public:
	Point2D();
	Point2D(int x, int y) : mX{x}, mY{y} {}

	void Print()
	{
		std::cout << "(" << mX << ", " << mY << ")" << std::endl;

	}

	friend Point2D operator +(const Point2D& a, const Point2D& b) //무명객체를 참조 할때는 무조건 const를 사용해야한다 - 우측값 참조	
	{
		Point2D newPt{ 0,0 };
		newPt.mX = a.mX + b.mX;
		newPt.mY = a.mY + b.mY;

		return newPt;
	}

	Point2D operator +(const Point2D& point)	// 멤버함수
	{
		Point2D result{ mX + point.mX, mY + point.mY };
		return result;
	}

	const Point2D& operator ++() // ++x 전위 연산자(단항) 매개변수가 없으면 전위
	{
		++mX;
		++mY;
		
		return (*this);
	}

	Point2D operator ++(int x) // ++x 후위 연산자 매개변수에 아무거나 넣어도 컴파일러가 알아먹음
	{
		Point2D temp(mX, mY);

		++mX;
		++mY;

		//++(*this);

		return temp;
	}

	operator const float()
	{
		return float(sqrt(mX * mX + mY * mY));
	}
};
class MyArray
{
private:
	int* mArray;
public:
	MyArray() : mArray{} {}
	MyArray(int count)
	{
		mArray = new int[count];
	}
	~MyArray()
	{
		delete[] mArray;
	}
	
	int& operator [](int index)
	{
		return mArray[index];
	}
	// mArray[0] = 1; 값을 대입하기 위해서는 L-value 즉 객체를 받아와야 하기 때문에 int&를 사용해야 한다 만약 int값을 반환 할 경우 R_value이기에 값 대입 X

	
};




int main()
{
	Point2D pt1{ 2,3 };
	Point2D pt2{ 4,5 };
	Point2D pt3{ 0,0 };
	

	pt3 = pt1 + pt2;	// pt1 + pt2에서 무명객체 생성
	pt3.Print();

	++pt3;
	pt3.Print();

	pt3++;
	pt3.Print();
	

	float length = pt3;
	std::cout << length << std::endl;
	
}


//#include <iostream>
//
//class MyClass
//{
//public:
//	int mValue;
//	MyClass(int value) : mValue{ value }
//	{
//		std::cout << "[ Myclass() ]" << mValue << std::endl;
//	}
//};
//
//MyClass operator +(MyClass c1, MyClass c2)
//{
//	return MyClass(c1.mValue + c2.mValue);
//}
//
//int Square(MyClass c) // (const MyClass c) 무명객체를 참조 할때는 무조건 const를 사용해야한다 - 우측값 참조
//{
//	return c.mValue * c.mValue;
//}
//
//int main()
//{
//	MyClass c1{ 1 }, c2{ 2 };
//	Square(c1 + c2);	// 생서자를 통해 만들어지긴 하지만 이름이 없으므로 사용 불가
//
//	
//}