#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> input;
	set<int>::iterator iter;
	input.insert(-1), input.insert(3), input.insert(-1), input.insert(5), input.insert(4);
	int findNum;	cin >> findNum;

	iter = input.begin();
	for (int i = 0; i < input.size() - findNum; i++)	*iter++;

	cout << *iter << endl;
}
