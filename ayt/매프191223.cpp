#include <iostream>
using namespace std;

int fib(int n) {
	int a = 0, b = 1, c = 0;
	int sum = 0;
	while (c < n)
	{
		c = a + b;
		a = b;
		b = c;
		if (c % 2 == 0)
		{
			sum += c;
		}
	}
	return sum;
}
int main()
{
	int N;
	cout << "Input:N = ";
	cin >> N;
	cout << "Output: " << fib(N) << endl;
}
