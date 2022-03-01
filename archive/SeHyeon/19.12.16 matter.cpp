#include <iostream>
using namespace std;
#define SIZE 5
#define Tri(n) ((n)*((n) + 1))/2

int main()
{
	int arr[SIZE];		for (int i = 0; i < SIZE; i++)	cin >> arr[i];
	int saveData[Tri(SIZE)] = { 0, };

	for (int i = 0; i < SIZE; i++)		//삼각수의 일반항
		saveData[Tri(i)] = arr[i];

	int count = -1, standard;
	for (int i = 1; i < Tri(SIZE); i++) {
		count++;
		if (saveData[i] != NULL) {
			standard = i;
			count = 0;
			continue;
		}
		saveData[i] = saveData[standard] + saveData[standard - count];
	}

	int max = saveData[0];
	for(int i = 1; i < Tri(SIZE); i++)
		max = (max < saveData[i] ? saveData[i] : max);
	cout << max;
}
