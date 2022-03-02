#include <iostream>
using namespace std;

int missingN(int input[], int n) {
	int i;
	for (int i = 0; i < n; i++)
		if (input[i] != i + 1)	return i + 1;
	return -1;
}
