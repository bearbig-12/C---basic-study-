// EX 4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int x{}, y{};
    std::cin >> x >> y;

    //std::cout << "몫 : " << x / y << std::endl;
    //std::cout << "나머지 : " << x % y << std::endl;
    
    x = x ^ y;
    y = y ^ x;
    x = x ^ y;
     
    std::cout << "x = " << x << " y = " << y << std::endl;

}

