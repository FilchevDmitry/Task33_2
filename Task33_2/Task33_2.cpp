#include<iostream>
#include<vector>
#include<exception>
#include<ctime>

void completion(std::vector<int>& lake)
{
	lake.resize(9, 0);
	std::srand(std::time(nullptr));
	int count = 0;
	while (count<4)
	{
		int num = std::rand() % 9;
		if (count == 0)
		{
			lake.at(num)=1 ;
			count++;
		}
		else
		{
			if (lake[num] == 0)
			{
				lake.at(num) = 2;
				count++;
			}
		}
	}
}
bool fishing(std::vector<int>& lake, int num)
{
	if (lake.at(num) == 1)
	{
		throw std::exception ("fish");
	}
	else if (lake.at(num) == 2)
	{
		throw std::exception("boot");
	}
	else
	return false;
}

int main()
{
	std::vector<int> lake;
	bool end = true;
	int choise = NULL;
	int counter = 0;
	completion(lake);
	while (end)
	{
		std::cout << "Enter a number from 1-9 : ";
		std::cin >> choise;
		try
		{
			if (!fishing(lake, choise-1))
			{
				std::cout << "Failure try again\n";
				++counter;
			}
		}
		catch(const std::exception& ex)
		{
			std::string temp = ex.what();
			if (temp == "fish")
			{
				std::cerr << "Congratulations You caught a " << ex.what() << " - " << " attempts : " << counter << std::endl;;
				end = false;
			}
			if (temp == "boot")
			{
				std::cerr << "You have caught the shoe the game is over\n";
				end = false;
			}
		}
	}
}
