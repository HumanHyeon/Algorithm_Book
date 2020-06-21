// "./"과 "../" 이 포함된 파일 경로를 "./"과 "../"이 없는 유닉스 파일 경로로 바꾸시오.

// "./"는 현재의 위치를 뜻하고, "../"는 상위 디렉토리를 뜻합니다.

// Given a file path containing "./" and "../", convert the path to a unix standard file path that does not contain "./" and "../".



// input: "/usr/bin/../"

// output: "/usr/"



// input: "/usr/./bin/./test/../"

// output: "/usr/bin/"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// void firstidea(string input)
// {
//     char tempinput;

//     do
//     {
//         cin >> tempinput;
//         if(tempinput == '.')
//         {
//             input.pop_back();
//             continue;
//         }            
//         else
//         {
//             input.push_back(tempinput);
//         }
//     } while (tempinput == '\n');
    
// }

// void secondidea(string input)
// {
//     string temp;
//     string wd = "./";   string pd = "../";
//     string::iterator searchpoint;

//     searchpoint = input.begin();

//     do
//     {
//         if (*searchpoint == '.')
//         {
//             if (*++searchpoint == '.')
//             {
//                 for (string::iterator i = searchpoint; *i == '/'; i--)
//                 {
//                     temp.pop_back();
//                 }
//             }
//             else
//             {
//                 temp.pop_back();
//             }
            
//         }
//         else
//         {
//             temp.push_back(*searchpoint);
//         }
//         searchpoint++;
//     } while (*searchpoint == NULL);

//     cout << temp;
// }

void thirdidea(string input)
{
	string temp = "";
	string wd = "./";   string pd = "../";
	vector<int>::iterator cleanstate1, cleanstate2;
	vector<int> pdselector, wdselector;
	int change = 2;

	for (int i = 0; i < input.size(); i++)
	{
		pdselector.push_back(input.find(pd, i));
		wdselector.push_back(input.find(wd, i));
	} //효율적으로 변환가능, ex) 벡터에 필요한 위치값을 넣은 다음, i 값을 그 위치로 옮김.

	cleanstate1 = unique(pdselector.begin(), pdselector.end());
	cleanstate2 = unique(wdselector.begin(), wdselector.end());

	pdselector.resize(distance(pdselector.begin(), cleanstate1));
	wdselector.resize(distance(wdselector.begin(), cleanstate2));
	
	for (int i = 0; i < wdselector.size(); i++)
	{
		input.erase(wdselector[i], wdselector[i] + 1);
	}

	for (int i = 0; i < pdselector.size(); i++)
	{
		input.erase(pdselector[i] - 1, pdselector[i] + 2);
		while (input[pdselector[i] - change] != '/')
		{
			input.erase(pdselector[i] - change);
			change++;
		}
	}
	cout << input;
}
int main()
{
    string input;

    cin >> input;

    thirdidea(input);

    return 0;
}
