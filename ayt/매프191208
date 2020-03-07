#include <iostream>
using namespace std;

int main(void) {
	int input[5] = { 1,2,3,4,5 };
	int output[5][4] = { {input[1],input[2],input[3],input[4]}
						,{input[0],input[2],input[3],input[4]}
		                ,{input[0],input[1],input[3],input[4]}
						,{input[0],input[1],input[2],input[4]}
						,{input[0],input[1],input[2],input[3]}
	};
	int sum;

	cout << "input : ";
	for (int i = 0; i < 5; i++) {
		cout << input[i] << ", ";
	}
	for (int i = 0; i < 5; i++) {
		sum = output[i][0] * output[i][1] * output[i][2] * output[i][3];
		input[i] = sum;
	}
	cout << "\n";
	cout << "output : ";
	for (int i = 0; i < 5; i++) {
		cout << input[i] << ", ";
	}
}
