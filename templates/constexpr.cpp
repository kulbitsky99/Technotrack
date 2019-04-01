#include <iostream>
#include <vector>

constexpr int max(const int a, const int b)
{
	return (a > b)? a : b;
}

int main()
{
	const int N = max(1, 2);
	struct A
	{
		int data[N];
	};
	return 0;
}

