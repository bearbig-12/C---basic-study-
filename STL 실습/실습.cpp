#include <iostream>
#include <vector>
#include <map>

class Student
{
public:
    int mNumber;
    std::string mName;
    int mScore;

    Student(int number, std::string name, int score) : mNumber(number), mName(name), mScore(score)
    {

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

void Add(Student student, std::vector<Student>& v, unsigned int seat_number)
{
    v.insert(v.begin() + (seat_number - 1), student);
}
void Erase(int number, std::vector<Student>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (number == v[i].mNumber)
        {
            std::cout << "Delete : " << v[i].mNumber << " , " << v[i].mName << " , " << v[i].mScore << std::endl;
            v.erase(v.begin()+i);
        }
    }
}
void Print(std::vector<Student> v)
{
    for (auto e : v)
    {
        std::cout << e.mNumber << " , "  << e.mName << " , " << e.mScore << std::endl;
    }
}

int Total_Score(std::vector<Student>& v)
{
    int Total = 0;
    for (auto e : v)
    {
        Total += e.mScore;
    }
    std::cout << "Total : " << Total << std::endl;
    return Total;
}

int Average(std::vector<Student>& v)
{
    int Total = Total_Score(v);
    int average = Total / v.size();

    std::cout << "Average : " << average << std::endl;

    return average;
}
void Above_Average(std::vector<Student>& v)
{
    int average = Average(v);
    for (int i = 0; i < v.size(); ++i)
    {
        if (average < v[i].mScore)
        {
            std::cout << "Æò±Õ ÀÌ»ó " << v[i].mNumber << " , " << v[i].mName << " , " << v[i].mScore << std::endl;
            
        }
    }


}

//int main()
//{
//    Student s1{ 1,"Kim",80 };
//    Student s2{ 2,"Lee",20 };
//    Student s3{ 3,"Park",50 };
//    Student s4{ 4,"Choi",30 };
//    
//    std::vector<Student> v{s1, s2, s3};
//    
//    Add(s4, v, 1);
//  
//
//    Print(v);
//
//    //Erase(3, v);
//
//    Total_Score(v);
//    Average(v);
//    Above_Average(v);
//    
//}