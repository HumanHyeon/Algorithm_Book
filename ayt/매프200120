#include <iostream>
using namespace std;

int result[11] = { 0, };

void interval(int n[3][2]) {
	for (int i = 0; i < 3; i++)
		for (int j = n[i][0]; j <= n[i][1]; j++)
			result[j] = 1;
	for (int i = 0; i < 10; i++) {
		if (result[i] == 1 && ((result[i - 1] != 1) || (result[i + 1] != 1)))
			cout << i << " ";
		if (result[i + 1] == 0)
			cout << endl;
	}
}

int main()
{
	int n[3][2] = { 0, };
	cout << "Input " << endl;
	for (int i = 0; i < 3; i++)
			cin >> n[i][0] >> n[i][1];       //2 4 Enter 1 5 Enter 7 9 Enter
	cout << "Ouput " << endl;
	interval(n);

	return 0;
}
