#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	int answer = 65536;
	string tmp = "";
	vector<string> vTmp1;
	vector<string> vTmp2;

	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	for (int i = 0; i < str1.size() - 1; ++i) {
		if ('a' <= str1[i] && str1[i] <= 'z')
			tmp += str1[i];
		if ('a' <= str1[i + 1] && str1[i + 1] <= 'z')
			tmp += str1[i + 1];

		if (tmp.size() == 2)
			vTmp1.push_back(tmp);
		tmp = "";
	}

	for (int i = 0; i < str2.size() - 1; ++i) {
		if ('a' <= str2[i] && str2[i] <= 'z')
			tmp += str2[i];
		if ('a' <= str2[i + 1] && str2[i + 1] <= 'z')
			tmp += str2[i + 1];

		if (tmp.size() == 2)
			vTmp2.push_back(tmp);
		tmp = "";
	}

	vector<string> vgjh(vTmp1.size() + vTmp2.size());
	vector<string> vhjh(vTmp1.size() + vTmp2.size());

	sort(vTmp1.begin(), vTmp1.end());
	sort(vTmp2.begin(), vTmp2.end());

	auto iter = set_intersection(vTmp1.begin(), vTmp1.end(), vTmp2.begin(), vTmp2.end(), vgjh.begin());
	vgjh.erase(iter, vgjh.end());
	iter = set_union(vTmp1.begin(), vTmp1.end(), vTmp2.begin(), vTmp2.end(), vhjh.begin());
	vhjh.erase(iter, vhjh.end());

	if (vgjh.size() != 0 || vhjh.size() != 0)
		answer *= ((double)vgjh.size() / vhjh.size());

	return answer;
}
