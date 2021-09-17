#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string x, y;
	std::cin >> x;
	std::cin >> y;
	if (x >= y) 
	{
		x = y;
	}
	std::cin >> y;
	if (x >= y) 
	{
		x = y;
	}
	std::cout << x;
	return 0;
}