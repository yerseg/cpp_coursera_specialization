#include <iostream>

int main()
{
	int A, B;
	std::cin >> A >> B;
	for (int i = A; i <= B; i++)
		if (i % 2 == 0) 
			std::cout << i << ' ';
	return 0;
}
