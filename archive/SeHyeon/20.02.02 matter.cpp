#include <iostream>
using namespace std;
#define DO_NOT_FIND NULL

int main() {
	int arr[] = { 3, 3, 3 };
	int firstBig, secondBig = DO_NOT_FIND;
	firstBig = arr[0];

	for (int i = 1; i < (sizeof(arr) / sizeof(*arr)); i++) {
		if (arr[i] > firstBig) {
			secondBig = firstBig;
			firstBig = arr[i];
		}
		else if (arr[i] < firstBig) {
			if (arr[i] > secondBig)
				secondBig = arr[i];		
		}
	}

	if (secondBig == DO_NOT_FIND)	cout << "Does not exist" << endl;
	else	cout << secondBig << endl;
}
