#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
using namespace std;

tuple<int, int> solution(vector<int> input, int target) {
	unordered_map<int, int> map;
	tuple<int, int> answer = make_tuple(-1, -1);

	for (int i = 0; i < input.size(); i++) {
		int remain = target - input[i];
		auto search = map.find(remain);

		if (search != map.end()) {
			answer = make_tuple(search->second, i);
			return answer;
		}
		map.insert({ input[i], i });
	}
}

int main() {
	vector<int> arr = { 2, 8, 5, 4, 1 };
	int target;	 cin >> target;
	
	cout << get<0>(solution(arr, target)) << " " << get<1>(solution(arr, target)) << endl;
	
} 
