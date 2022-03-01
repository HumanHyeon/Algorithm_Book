#include <iostream>
using namespace std;
#define SIZE 20

int main() {
	int range[SIZE] = { 0, };
	while (true) {
		int start, end;		cin >> start >> end;
		if (start == -1 || end == -1) break;
		
		for (int i = start - 1; i < end; i++) {
			range[i] = 1;
		}
	}
	
	int st = 0, en = 0;
	bool con = false;
	for (int i = 0; i < SIZE; i++) {
		if (range[i] && !con) {
			st = i + 1;
			con = true;
		}
		if (!range[i] && con) {
			en = i;
			con = false;
		}

		if (st && en) {
			cout << st << " " << en << endl;
			st = en = 0;
		}
	}
}
