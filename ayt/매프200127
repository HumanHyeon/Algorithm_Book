#include <iostream>
using namespace std;

char result[100];
char temp[10];

void Reverse(char temp[100]) {
	int t1 = 0, t2 = 0;
	for (int i = 0; i < 100; i++) {
		if (temp[i] == ' ') {
			for (int j = i - 1; j >= t2; j--) {
				result[t1] = temp[j];
				t1++;
			}
			t2 = ++t1;
		}
	}
}

int main()
{
	char inp[100] = "abc 123 apple ";
	cout << "Input: " << inp << endl;
	Reverse(inp);
	cout << "Output: ";
	for (int i = 0; i < 100; i++)
		cout << result[i];

	return 0;
}
