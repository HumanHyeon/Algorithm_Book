
#include<stdio.h>
#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;
//길이가 같은 두 문자열(string) A 와 B가 주어지면, A 가 B 로 1:1 암호화 가능한지 찾으시오.
string A = "ABBCD";
string B = "APPLE";
char Ismatch[10] = {'\0',}; //A의 n번째 글자와 1ㄷ1 매치되는 B의 글자가 들어감
int main() {
	if (A.length() != B.length()) { //문자열 A와 B의 길이가 같지 않을 경우
		cout << "False\n"; getchar();  return 0;
	}	
	Ismatch[0] = B.at(0); //어차피 첫글자는 무조건 True
	for (int i = 1; i < A.length(); i++) {
		for (int j = 0; j < i; j++) {
			if (A.at(j) == A.at(i)) { //앞의 어딘가의 글자와 같은 글자일 경우
				if (Ismatch[j] != B.at(i)) { cout << "False\n"; getchar(); return 0; }
			}//앞 어딘가와 일치하는 글자가 아닐 경우
			else if (Ismatch[j] == B.at(i)) { cout << "False\n"; getchar(); return 0; }
			else { Ismatch[i] = B.at(i); }
		}
	}	
	cout << "True\n";
	getchar();
	return 0;
}