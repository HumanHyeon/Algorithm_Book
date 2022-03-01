#include <string>
#include <vector>
#include <map>
#include <algorithm>
//#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;

	for (int i = 0; i < genres.size(); ++i) {
		m[genres[i]] = 0;
	}
	
	for (int i = 0; i < genres.size(); ++i) {
		m[genres[i]] += plays[i];
	}

	int size = 0;
	bool tf = false;
	while (1) {
		if (tf) break;
		size = answer.size();
		int a = 0;
		string b = "";

		for (auto elem : m) {
			if (elem.second > a) {
				a = elem.second;
				b = elem.first;
			}
		}

		vector<int> iTmp;
		for (int j = 0; j < 2; ++j) {
			int tmp = 0;
			int index = -1;
			bool ck = false;
			for (int i = 0; i < plays.size(); ++i) {
				if (genres[i] == b && plays[i] > tmp) {
					tmp = plays[i];
					index = i;
					ck = true;
				}
			}
			if (ck) {
				iTmp.push_back(index);
				plays[index] = 0;
			}
		}

		/*for (auto elem : iTmp)
			cout << elem << " ";
		cout << endl;*/

		m[b] = -999999999;

		/*if (iTmp.size() != 1)
			sort(iTmp.rbegin(), iTmp.rend());*/

		for (int i = 0; i < iTmp.size(); ++i)
			answer.push_back(iTmp[i]);

		if (answer.size() == size) tf = true;
	}

	return answer;
}
