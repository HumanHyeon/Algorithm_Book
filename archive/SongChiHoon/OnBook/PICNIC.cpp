#include <iostream>
#include <vector>
using namespace std;

bool friendship[10][10] = {};
int countingarray;

int main()
{
	int casenum, studentnum, friendnum, temp = 0;

	cout << "케이스 수 입력 : ";    cin >> casenum;

	while (casenum != 0)
	{
		cout << "학생 수와 친구 수 입력 : ";    cin >> studentnum;  cin >> friendnum;
		cout << endl << "친구 쌍 입력하기" << endl;

		vector<bool> friendinfo;

		for (int i = 0; i < friendnum * 2; i++)
			cin >> temp;
			friendinfo.push_back(temp);


		casenum--;
	}

	return 0;

}