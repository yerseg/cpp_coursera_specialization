#include <iostream>

int main()
{
	double N, A, B, X, Y;
	std::cin >> N >> A >> B >> X >> Y;
	double ans = N;
	if (N > A)
		ans = ((100 - X) / 100) * N;
	if (N > B)
		ans = ((100 - Y) / 100) * N;
	std::cout << ans;
	return 0;
}
