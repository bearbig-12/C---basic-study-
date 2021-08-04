#include <iostream>

int main()
{
	int Age;
	int Distance;
	char Pay_type;


	

	std::cout << " Hello this is KORAIL, please Insert following data. " << std::endl;
	std::cout << " 1. Your age, 2. Distance, 3. Pay_Tpye(ex Traffic Card = T, Cash = C) : ";

	std::cin >> Age >> Distance >> Pay_type;

	bool Child = ((Age >= 6) && (Age < 13));
	bool Teenager = ((Age >= 13) && (Age < 18));
	bool Adult = Age >= 19;


	if (Pay_type == 'T')
	{
		
		if (Child)
		{
			if (Distance <= 10)
			{
				std::cout << " You need to pay : " << " 450 won";

			}
			else if ((Distance > 11) && Distance <= 15)
			{
				std::cout << " You need to pay : " << " 500 won";
			}
			else if ((Distance > 16) && Distance <= 20)
			{
				std::cout << " You need to pay : " << " 550 won";
			}
		}
		else if (Teenager)
		{
			if (Distance <= 10)
			{
				std::cout << " You need to pay : " << " 720 won";

			}
			else if ((Distance > 11) && Distance <= 15)
			{
				std::cout << " You need to pay : " << " 800 won";
			}
			else if ((Distance > 16) && Distance <= 20)
			{
				std::cout << " You need to pay : " << " 880 won";
			}
		}
		else if (Adult)
		{
			if (Distance <= 10)
			{
				std::cout << " You need to pay : " << " 1250 won";

			}
			else if ((Distance > 11) && Distance <= 15)
			{
				std::cout << " You need to pay : " << " 1350 won";
			}
			else if ((Distance > 16) && Distance <= 20)
			{
				std::cout << " You need to pay : " << " 1450 won";
			}
		}


	}
	else if (Pay_type == 'C')
	{
		if (Child)
		{
			if (Distance <= 10)
			{
				std::cout << " You need to pay : " << " 450 won";

			}
			else if ((Distance > 11) && Distance <= 15)
			{
				std::cout << " You need to pay : " << " 500 won";
			}
			else if ((Distance > 16) && Distance <= 20)
			{
				std::cout << " You need to pay : " << " 550 won";
			}
		}
		else if (Adult)
		{
			if (Distance <= 10)
			{
				std::cout << " You need to pay : " << " 1350 won";

			}
			else if ((Distance > 11) && Distance <= 15)
			{
				std::cout << " You need to pay : " << " 1450 won";
			}
			else if ((Distance > 16) && Distance <= 20)
			{
				std::cout << " You need to pay : " << " 1550 won";
			}
		}
	}
}