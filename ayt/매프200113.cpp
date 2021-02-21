#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
using namespace std;

tuple<int, int> sumIndex(vector<int> arr, int n)
{
	unordered_map<int, int> map;
	tuple<int, int> answer = make_tuple(-1, -1);

	for (int i = 0; i < arr.size(); i++)
	{
		int remain = n - arr[i];
		auto search = map.find(remain);
		if (search != map.end())
		{
			answer = make_tuple(search->second, i);
			return answer;
		}
		map.insert({ arr[i], i });
	}

	return answer;
}

int main()
{
	int target;
	int inp;
	vector<int> input;
	cout << "Input: ";
	for (int i = 0; i < 5; i++) {             //????
		cin >> inp;
		input.push_back(inp); 
	}
	cin >> target;
	cout << "Ouput: " << get<0>(sumIndex(input, target)) << ", " << get<1>(sumIndex(input, target)) << endl;

	return 0;
}
