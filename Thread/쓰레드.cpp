#include <iostream>
#include <thread>
#include <mutex>

std::mutex gMutex;	// 임계구역

void PrintNumber()
{
	
	for (int i = 0; i < 999; ++i)
	{
		if (gMutex.try_lock())
		{
			++i;
			std::cout << "worker 1 : " << i << std::endl;
			gMutex.unlock();
		}
		
	}
	


}

void PrintAscii()
{
	for (int repeat = 0; repeat < 90; ++repeat)
	{
		for (int i = 33; i < 126; ++i)
		{
			if (gMutex.try_lock())
			{
				++i;
				std::cout << "Woker2 : " << char(i) << std::endl;
				gMutex.unlock();
			}
		
		}
	}
}

int main()
{
	std::thread job1(PrintNumber);
	std::thread job2(PrintAscii);

	job1.join();
	job2.join();
}