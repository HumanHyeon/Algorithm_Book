#include <iostream>
#include <algorithm>
using namespace std;

void change(int* in) {
	int index = 0;
	for (int i = 0; i < 5; i++) {
		if (in[i] != 0) {
			swap(in[i],in[index]);
			index++;
		}
	}
}

int main()
{
	int input[] = { 0,5,0,3,-1 };
	for (int i = 0; i < 5; i++)
		cout << " " << input[i];
	change(input);
	cout << "\n";
	for (int i = 0; i < 5; i++)
		cout << " " << input[i];
	cout << "\n";

	return 0;
}
