#include <iostream>
#include <vector>
using namespace std;

int findGCD(vector<int>& input) {
	int min = 987654321;
	bool ok = true;

	for (int i = 0; i < input.size(); i++)
		if (min > input[i])	min = input[i];
	for (int i = 0; i < input.size(); i++)
		if (input[i] % min) {
			ok = false;	
			break;
		}

	if (ok)	return min;
	else return 1;
}

int main() {
	vector<int> input;
	int arr[] = {2, 4, 6, 8, 9};
	
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		input.push_back(arr[i]);

	int gcd = findGCD(input);
	cout << gcd << endl;
}
