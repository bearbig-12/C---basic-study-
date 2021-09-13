#include <iostream>

class Calendar
{
private:
	int mMonth;
public:
	//setter
	void SetMonth(int month)
	{
		if (month >= 1 && month <= 12)
		{
			mMonth = month;
		}
	}
	void SetMonth(std::string month)
	{
		if (month == "jan")
		{
			mMonth = 1;
		}
	}

	//getter
	
	std::string GetMonth() const
	{
		switch (mMonth)
		{
		case 1:
			return "Jan";
		default:
			break;
		}
	}
};