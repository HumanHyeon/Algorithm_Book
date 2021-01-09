#include <string>
#include <vector>
using namespace std;

bool Correct(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '(')
			sum++;
		else if (s.at(i) == ')')
			sum--;
		if (sum < 0)
			return false;
	}
	return true;
}

string func(string s) {
	if (s == "")
		return "";
	string u; string v;
	int i = 0;
	int left = 0; int right = 0;
	for (i = 0; i < s.length(); i++) {
		if (s.at(i) == '(')
			left++;
		else if (s.at(i) == ')')
			right++;
		if (left == right) {
			u = s.substr(0, i + 1);
			v = s.substr(i + 1);
			break;
		}
	}
	if (Correct(u))
		return u + func(v);
	else {
		string temp = "(" + func(v) + ")";
		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.length(); i++) {
			if (u.at(i) == '(')
				temp = temp + ')';
			else
				temp = temp + '(';
		}
		return temp;
	}
}

string solution(string p) {
	return func(p);
}
