#pragma once
class Date
{
private:
	int mDay;
	int mMonth;
	int mYear;
public:
	Date(int day = 0, int month = 0, int year = 0)
	{
		mDay = day;
		mMonth = month;
		mYear = year;
	}
	void Print();
};

