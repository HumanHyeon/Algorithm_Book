#include <iostream>
using namespace std;


int main() {
	int arr[] = {0, 5, 0, 3, -1};

	int interval = 0;
	for (int i = 0; i + interval < (sizeof(arr) / sizeof(*arr)); i++) {
		if ((i + interval) >= (sizeof(arr) / sizeof(*arr)) - 1)	interval--;
		if (arr[i] == 0) {
			++interval;
			arr[i] = arr[i + interval];
			arr[i + interval] = 0;
		}
		else {
			arr[i] = arr[i + interval];
		}
	}


	for (int i = 0; i < (sizeof(arr) / sizeof(*arr)); i++)
		cout << arr[i] << " ";
}
