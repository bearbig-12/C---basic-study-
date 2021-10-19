#include <iostream>
#include<future>
void PrintInt()
{
	for (int i = 0; i < 500; ++i)
	{
		std::cout << "Worker 1 : " << i << std::endl;
	}
}

void Printfloat()
{
	for (float i = 0.0f; i < 500.0f; ++i)
	{
		std::cout << "Worker 2 : " << i << std::endl;
	}
}

int main()
{
	// 비동기
	std::future<void> async1 = std::async(PrintInt);
	std::future<void> async2 = std::async(Printfloat);

	std::cout << "작 업 끝 !" << std::endl;

	async1.get();
	std::cout << "worker1 완료" << std::endl;
}