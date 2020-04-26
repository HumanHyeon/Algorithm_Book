#include <iostream>
#define SIZE 3
using namespace std;

int input[][SIZE] =
{ {1,2,3},
{8,9,4},
{7,6,5},
};

//int input[][SIZE] =
//{ {1,2,3,4},
//{12,13,14,5},
//{11,16,15,6},
//{10,9,8,7}
//};

//int input[][SIZE] =
//{ {1,2,3,4,5},
//{16,17,18,19,6},
//{15,24,25,20,7},
//{14,23,22,21,8},
//{13,12,11,10,9}
//};

void circular(int i, int j, int s1, int s2) {
	if (input[i][j] == input[s1 - 1][s1 - 1]) {
		cout << input[i][j];
		return;
	}
	while (j < s1) {
		cout << input[i][j] << " ";
		j++;
	}
	j--;
	while (i < s1 - 1) {
		cout << input[i + 1][j] << " ";
		i++;
	}
	while (j > s2) {
		cout << input[i][j - 1] << " ";
		j--;
	}
	while (i > s2 + 1) {
		cout << input[i - 1][j] << " ";
		i--;
	}
	j++;
	circular(i, j, s1 - 1, s2 + 1);
}

int main() {
	int i = 0;
	int j = 0;
	int s1 = SIZE;
	int s2 = 0;

	circular(i, j, s1, s2);

	return 0;
}
