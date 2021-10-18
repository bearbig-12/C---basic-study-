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
    std::cout << "-----����ȣ ~ �� ~-----" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "[1] - �л� �߰� " << std::endl;
    std::cout << "[2] - �л� ���� " << std::endl;
    std::cout << "[3] - ��ü �л� ��� " << std::endl;
    std::cout << "[4] - ��� �� ���� ��� " << std::endl;
    std::cout << "[5] - ��� �̻� " << std::endl;
    std::cout << "[6] - ����! " << std::endl;
    std::cout << "[7] - �� ����� " << std::endl;

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

            std::cout << " �л� ��ȣ : ";
            if (!(std::cin >> number))
            {
                std::cout << "You put wrong value " << std::endl;
                break;
            }
            std::cout << std::endl;

            std::cout << " �л� �̸� : ";
            if (!(std::cin >> name))
            {
                std::cout << "You put wrong value " << std::endl;
                break;
            }
            std::cout << std::endl;

            std::cout << " �л� ���� : ";
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
            std::cout << "������� �ϴ� �л��� �л� ��ȣ : ";
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
            std::cout << "��ü ����" << std::endl;
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
        std::cout << "�� ���� �Դϴ�." << std::endl;
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
    std::cout << " ��� : " << Average << std::endl;
    std::cout << " ��Ż : " << Total << std::endl;
    return std::pair<int, int> (Total, Average);         // �츮�� ����̻��� ������� ���ؾ��ϱ� ������ ��Ż�� ��ȯ �ʿ䰡 ����
}
void Above_Aver(std::map<int, Student>& m)
{
    int aver = AverTotal(m).second;
    int total = AverTotal(m).first;

    std::for_each(m.begin(), m.end(), [&](auto& pair)
        {  
            if (aver <= pair.second.mScore)
            std::cout << "��� �̻� : " << pair.first << " : " << pair.second.mName << " , " << pair.second.mScore << std::endl; 
        }
    );


    //for (auto pair : m)
    //{
    //    if (aver < pair.second.mScore)
    //    {
    //        std::cout << "��� �̻� : " << pair.first << " : " << pair.second.mName << " , " << pair.second.mScore << std::endl;
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
 

    std::cout << "���� ���� ������� ������ �ϳ� ���� 7�� 15�� ���� ���� 1�� 15�� ����" << std::endl;
}

