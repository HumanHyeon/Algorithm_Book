#include <iostream>
using namespace std;

int missingN(int input[], int n) {
	int answer = (n + 1) * (n + 2) / 2;	//1개 빠진 개수이니 n + 1
	for (int i = 0; i < n; i++)
		answer -= input[i];
	return answer;
}
