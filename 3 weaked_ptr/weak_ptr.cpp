#include <iostream>

//		std::weak_ptr
//			shared_ptr인데 reference count에 영향을 주지 않음

int main()
{
	std::unique_ptr p = std::make_unique<M