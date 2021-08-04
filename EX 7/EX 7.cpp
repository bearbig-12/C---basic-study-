#include <iostream>

int main()
{
	int Input_money{};
	const double Dollar_exchange_rate = 1147.20;
	const double Yen_exchange_rate = 10.41;
	const double Pound_exchange_rate = 1589.79;
	const double Euro_exchange_rate = 1358.52;
	char MoneyKind;
	double temp{ 0 };
	

	std::cout << "Please Insert the Money you have ";
	
	std::cout << "Pleas Insert Money type which you have (ex yen = Y, dollar = S, Pound = P, Euro = E ) : ";
	std::cin >> Input_money >> MoneyKind;

	switch (MoneyKind)
	{
	case 'S':
		std::cout << "You have : " << Input_money << " as a dollar" << std::endl;
		temp = Input_money * Dollar_exchange_rate;
		break;
	case 'Y':
		std::cout << "You have : " << Input_money << " as a yen" << std::endl;
		temp = Input_money * Yen_exchange_rate;
		break;
	case 'P':
		std::cout << "You have : " << Input_money << " as a POUND" << std::endl;
		temp = Input_money * Pound_exchange_rate;
		break;
	case 'E':
		std::cout << "You have : " << Input_money << " as a EURO" << std::endl;
		temp = Input_money * Euro_exchange_rate;
		break;
	default:
		std::cout << "Not vaild type " << std::endl;
		break;
	}
	std::cout << "You have : " << temp << "as KR won";
	
	/*if (MoneyKind == 'S')
	{
		std::cout << "You have : " << Input_money << " as a dollar" << std::endl;
		std::cout << "You have : " << Input_money * Dollar_exchange_rate << " as KR won";
	}
	else if (MoneyKind == 'Y')
	{
		std::cout << "You have : " << Input_money << " as a yen" << std::endl;
		std::cout << "You have : " << Input_money * Yen_exchange_rate << "as KR won";
	}
	else
	{
		std::cout << "It is not valid type, please try again" << std::endl;
		return 0;
	}*/
	


 
	return 0;
}