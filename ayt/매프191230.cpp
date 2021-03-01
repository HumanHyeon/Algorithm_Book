#include <iostream>
#include <vector>
using namespace std;

void outputString(int num, int open, int close, string s, vector<string> list)
{
	if (close == num)
	{
		list.push_back(s);
		return;
	}

	if (open < num)
		outputString(num, open + 1, close, s + "(", list);

	if (close < open)
		outputString(num, open, close + 1, s + ")", list);
}

vector<string> output(int n) {
	vector<string> list;
	outputString(n, 0, 0, " ", list);
	return list;
}

int main()
{
	int N;
	vector<string> result;

	cout << "Input: ";
	cin >> N;
	result = output(N);
	cout << result.front() << endl;

	cout << "Output: [" ;
	for (vector<int>::size_type i = 0; i << result.size(); i++)
		cout << result.at(i) << " ";
	cout << "]" << endl;

	return 0;
}
