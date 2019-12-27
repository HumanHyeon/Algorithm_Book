#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long first = 0, second = 1, answer = 0;	//first is f(x)'s answer
	int limit;		cin >> limit;

	vector<long long> saveFB;

	while(true){
		long long tmp = second;
		second += first;
		first = tmp;

		if (first > limit) break;
		saveFB.push_back(first);
	}

	for (vector<long long>::iterator iter = saveFB.begin(); iter != saveFB.end(); iter++) {
		if (!(*iter % 2))	answer += *iter;
		//cout << *iter << " ";
	}
	cout << answer << endl;
}
