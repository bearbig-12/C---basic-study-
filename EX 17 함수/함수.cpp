#include <iostream>

/// <summary>
/// 
/// </summary>
void PrintDottedLine()
{
	std::cout << "------------" << std::endl;
}

//숫자출력
//입력 정수
//출력 없음
void PrintNumber(int x)
{
	std::cout << x << std::endl;
}

// 주어진 수를 제곱하여 반환
// 입력 - 정수
// 출력 - 정수 제곱
int Square(int x)
{
	return x * x;
}
//1
double Max(double x, double y)
{
	/*if (x > y)
	{
		return x;
	}
	else if (y > x)
	{
		return y;
	}
	else
	{
		std::cout << " SAME " << std::endl;
		return 0;
	}*/
	return (x > y) ? x : y;
}

//2
int Read_Value()
{
	int x;
	std::cin >> x;
	return x;
}

void Writhe_Value(int x)
{
	std::cout << x << std::endl;
}

//3
int Quotient(int x, int y)
{
	int result{ 0 };
	if (x > y)
	{
		result = x / y;
	}
	else if (x < y)
	{
		result = y / x;
	}
	return result;
}
int Remainder(int x, int y)
{
	int result{ 0 };
	if (x > y)
	{
		result = x % y;
	}
	else if (x < y)
	{
		result = y % x;
	}
	return result;
}
void Read_Value2(int x, int y)
{
	std::cout << "Quotient is : " << x << " " << "Remainder is : " << y << std::endl;
}

//4
void GuGu_DAN(int x)
{
	std::cout << x << " 단 ! " << std::endl;
	for (int i = 1; i <= 9; ++i)
	{
		std::cout << x << " x " << i << " = " << x * i << std::endl;
	}
}

int main()
{
	//GuGu_DAN(5);

	//3 
	/*int x{ 0 };
	int y{ 0 };
	int Quo{ 0 };
	int Remain{ 0 };
	std::cin >> x >> y;
	Quo = Quotient(x, y);
	Remain = Remainder(x, y);
	Read_Value2(Quo, Remain);*/




	//2
	/*int result = 0;
	result = Read_Value();
	Writhe_Value(result);*/

	//1
	double x{0};
	double y{0};
	double result{0};
	std::cin >> x >> y;
	result = Max(x, y);
	std::cout << result << std::endl;

	//PrintDottedLine();
	//PrintNumber(4);
	//int result{ 0 };
	//result = Square(4);
	//PrintNumber(result);
}