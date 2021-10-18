#include <iostream>
#include <map>
#include <numeric>
#include <algorithm>
class Student
{
public:
    int mNumber;
    std::string mName;
    int mScore;

    Student(int number, std::string name, int score) : mNumber(number), mName(name), mScore(score)
    {

    }
    Student()
    {
        mNumber = 0;
        mName = "";
        mScore = 0;
    }
    ~Student()
    {

    }
    void Print()
    {
        std::cout <<
            "(" << mNumber << ") " <<
            mName << " : " <<
            mScore <<
            std::endl;
    }
};

enum Type
{
    ADD = 1,
    DELETE = 2,
    PRINTALL = 3,
    AVERAndTOTAL = 4,
    AboveAver = 5,
    Stop = 6,
    DELETEALL = 7
};


void Add(int s_number, std::string s_name, int s_score, std::map<int, Student>& m);
void Delete(std::map<int, Student>& m, int s_number);
void PrintAll(const std::map<int, Student>& m);
std::pair<int, int>  AverTotal(std::map<int, Student>& m);
void Above_Aver(std::map<int, Student>& m);
void DeleteAll(std::map<int, Student>& m);

void PrintInformation()
{
    std::cout << "-----무야호 ~ 맵 ~-----" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "[1] - 학생 추가 " << std::endl;
    std::cout << "[2] - 학생 제거 " << std::endl;
    std::cout << "[3] - 전체 학생 출력 " << std::endl;
    std::cout << "[4] - 평균 및 총점 출력 " << std::endl;
    std::cout << "[5] - 평균 이상 " << std::endl;
    std::cout << "[6] - 멈춰! " << std::endl;
    std::cout << "[7] - 다 지우기 " << std::endl;

    std::cout << "-----------------------------------" << std::endl;

}

void UserInput(std::map<int, Student>& student)
{
    int type{ 0 };
    

    while (true)
    {
       

        std::cout << std::endl;
        std::cout << " > ";
        std::cin >> type;
        if (type == ADD)
        {
            int number;
            std::string name;
            int score;

            std::cout << " 학생 번호 : ";
            if (!(std::cin >> number))
            {
                std::cout << "You put wrong value " << std::endl;
                break;
            }
            std::cout << std::endl;

            std::cout << " 학생 이름 : ";
            if (!(std::cin >> name))
            {
                std::cout << "You put wrong value " << std::endl;
                break;
            }
            std::cout << std::endl;

            std::cout << " 학생 점수 : ";
            if (!(std::cin >> score))
            {
                std::cout << "You put wrong value " << std::endl;
                break;
            }
            std::cout << std::endl;

            Add(number, name, score, student);
            

        }
        else if (type == DELETE)
        {
            int snumber;
            std::cout << "지우고자 하는 학생의 학생 번호 : ";
            std::cin >> snumber;
            Delete(student, snumber);

        }
        else if (type == PRINTALL)
        {
            PrintAll(student);
        }
        else if (type == AVERAndTOTAL)
        {
            AverTotal(student);
        }
        else if (type == AboveAver)
        {
            Above_Aver(student);
        }
        else if (type == Stop)
        {
            std::cout << "Stop the function" << std::endl;
            break;
        }
        else if (type == DELETEALL)
        {
            std::cout << "전체 삭제" << std::endl;
            DeleteAll(student);
        }
        else
        {
            std::cout << "Thas's not invalid type of number," << " please read information carfully" << std::endl;

        }
    }
}

void Add(int s_number, std::string s_name, int s_score ,std::map<int, Student>& m)
{
    Student student(s_number, s_name, s_score);
    m.insert({ s_number, student });
    
}
void Delete(std::map<int, Student>& m, int s_number)
{
    m.erase(s_number);
}
void PrintAll(const std::map<int, Student>& m)
{
    if (m.empty())
    {
        std::cout << "빈 파일 입니다." << std::endl;
    }
    for (auto pair : m)
    {
        std::cout << pair.first << " : " << pair.second.mName << " , " << pair.second.mScore << std::endl;
    }
}
std::pair<int, int> AverTotal(std::map<int, Student>& m)
{
    int Average = 0;
    int Total = std::accumulate(m.begin(), m.end(), 0, [](int accum, auto& pair)
                                                         {return accum += pair.second.mScore; }
                                                         );

    /*for (auto pair : m)
    {
        Total += pair.second.mScore;
    }*/

    Average = Total / m.size();
    std::cout << " 평균 : " << Average << std::endl;
    std::cout << " 토탈 : " << Total << std::endl;
    return std::pair<int, int> (Total, Average);         // 우리는 평균이상인 사람들을 구해야하기 때문에 토탈은 반환 필요가 읎음
}
void Above_Aver(std::map<int, Student>& m)
{
    int aver = AverTotal(m).second;
    int total = AverTotal(m).first;

    std::for_each(m.begin(), m.end(), [&](auto& pair)
        {  
            if (aver <= pair.second.mScore)
            std::cout << "평균 이상 : " << pair.first << " : " << pair.second.mName << " , " << pair.second.mScore << std::endl; 
        }
    );


    //for (auto pair : m)
    //{
    //    if (aver < pair.second.mScore)
    //    {
    //        std::cout << "평균 이상 : " << pair.first << " : " << pair.second.mName << " , " << pair.second.mScore << std::endl;
    //    }
    //}
}
void DeleteAll(std::map<int, Student>& m)
{
    m.clear();
}


int main()
{

    //Student s1{ 1,"Kim",80 };
    //Student s2{ 2,"Lee",20 };
    //Student s3{ 3,"Park",50 };
    //Student s4{ 4,"Choi",30 };

    std::map<int, Student> student;
    PrintInformation();
    UserInput(student);
    //std::pair<int, Student> pair(s1.mNumber, s1);
    //std::pair<int, Student> pair(s2.mNumber, s2);
    //std::pair<int, Student> pair(s3.mNumber, s3);
    //std::pair<int, Student> pair(s4.mNumber, s4);
 

    std::cout << "역대 가장 힘들었던 과제중 하나 오후 7시 15분 시작 새벽 1시 15분 종료" << std::endl;
}

