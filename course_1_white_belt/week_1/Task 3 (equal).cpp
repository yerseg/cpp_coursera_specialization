#include <cmath>
#include <iostream>

int main()
{
	double A, B, C;
	std::cin >> A >> B >> C;
	if (A != 0)
	{
		double D = B * B - 4 * A * C;
		if (D >= 0)
		{
			double x1 = (-B - std::sqrt(D)) / (2 * A);
			double x2 = (-B + std::sqrt(D)) / (2 * A);
			if (x1 == x2)
			{
				std::cout << x1;
			}
			else
			{
				std::cout << x1 << ' ' << x2;
			}
		}
		else;
	}
	else if (B != 0)
	{
		std::cout << - (C / B);
	}
	else;
	return 0;
}