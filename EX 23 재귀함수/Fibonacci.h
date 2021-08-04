#pragma once

int Fibo(int n)
{
	//base case
	if (n == 1 || n == 2)
	{
		return 1;
	}
	
	//recursive case
	return Fibo(n - 1) + Fibo(n - 2);
}
//void FiboPrint(int n)
//{
//	for (int i = 1; i <= n; ++i)
//	{
//		if (Fibo(i) > n)
//		{
//			return;
//		}
//		else
//		{
//			std::cout << Fibo(i) << " ";
//		}
//		
//	}
//}