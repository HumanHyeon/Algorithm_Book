#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	map<string, int> m;
	string tmp = "";
	
	for (int i = 0; i < s.size(); ++i) {
		if ('0' <= s[i] && s[i] <= '9') {
			tmp += s[i];
		}
		else if (tmp != "") {
			if (m.find(tmp) == m.end()) m[tmp] = 1;
			else ++m[tmp];
			tmp = "";
		}
	}

	int si = m.size();
	while (1) {
		if (answer.size() == si) break;
		string tmp = "";
		int tmp2 = 0;

		for (auto iter : m) {
			if (iter.second > tmp2) {
				tmp = iter.first;
				tmp2 = iter.second;
			}
		}

		m.erase(m.find(tmp));
		answer.push_back(stoi(tmp));
	}

	return answer;
}
