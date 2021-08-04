// EX 15 테트리스 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int block[3][3]{    //행(row) 렬(column) 만약(x,y) 식의 좌표로 나타낼시 행(row) = y 렬(column) = x
        {0, 1, 0},
        {0, 1, 1},
        {0, 1, 0}
    };
    std::cout << " << 테트리스 블럭 회전 >> " << std::endl;
    std::cout << " 1 : 왼쪽 회전, 2 : 오른쪽 회전, 3 : 종료" << std::endl;
    while (true)
    {
        // 블럭 출력
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                std::cout << block[row][col] << " ";
            }
            std::cout << std::endl;
        }
        //입력
        int rotate{};
        std::cout << " 회전 방향? ";
        std::cin >> rotate;

        //회전
        int rotate_block[3][3]{};
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                if (rotate == 1)
                {
                    //좌회전
                    rotate_block[2 - col][row] = block[row][col];
                }
                else
                {
                    //우회전
                    rotate_block[col][2 - row] = block[row][col];
                }
            }
            
        }
        // rotate_block -> block
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                block[row][col] = rotate_block[row][col];
            }
        }
        break;
    }

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
