#include <iostream>
#define Right 0
#define Down 1
#define Left 2
#define Up 3
using namespace std;
template<typename T>

void printSwirl(T& input) {
	int x_size, y_size;
	x_size = sizeof(input[0]) / sizeof(input[0][0]);
	y_size = sizeof(input) / sizeof(input[0]);

	int count = 0, flag = Right;
	int x0 = x_size, y1 = y_size, x2 = 0, y3 = 1;

	while(count != (sizeof(input) / sizeof(input[0][0]))){
		switch (flag)
		{
		case Right:
			for (int i = x_size - x0; i < x0; i++, count++)
				cout << input[y_size - y1][i] << " ";
			x0--, flag = Down;
			break;
		case Down:
			for (int i = y_size - y1 + 1; i < y1; i++, count++)
				cout << input[i][x_size - x2 - 1] << " ";
			y1--, flag = Left;
			break;
		case Left:
			for (int i = x_size - x2 - 2; i >= x2; i--, count++)
				cout << input[y_size - y3][i] << " ";
			x2++, flag = Up;
			break;
		case Up:
			for (int i = y_size - y3 - 1; i >= y3; i--, count++)
				cout << input[i][x_size - x0 - 1] << " ";
			y3++, flag = Right;
			break;
		default:
			cout << "error" << endl;
			break;
		}
	}
}

int main() {
	/*int input[][4] = {
		{1, 2, 3, 4},
		{12, 13, 14, 5},
		{11, 16, 15, 6},
		{10, 9, 8, 7}
	};*/
	char input[][4] = {
	{'a', 'b', 'c', 'd'},
	{'j', 'k', 'l', 'e'},
	{'i', 'h', 'g' ,'f'}
	};
	printSwirl(input);
}
