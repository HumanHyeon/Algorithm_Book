
#include<stdio.h>
#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;
//���̰� ���� �� ���ڿ�(string) A �� B�� �־�����, A �� B �� 1:1 ��ȣȭ �������� ã���ÿ�.
string A = "ABBCD";
string B = "APPLE";
char Ismatch[10] = {'\0',}; //A�� n��° ���ڿ� 1��1 ��ġ�Ǵ� B�� ���ڰ� ��
int main() {
	if (A.length() != B.length()) { //���ڿ� A�� B�� ���̰� ���� ���� ���
		cout << "False\n"; getchar();  return 0;
	}	
	Ismatch[0] = B.at(0); //������ ù���ڴ� ������ True
	for (int i = 1; i < A.length(); i++) {
		for (int j = 0; j < i; j++) {
			if (A.at(j) == A.at(i)) { //���� ����� ���ڿ� ���� ������ ���
				if (Ismatch[j] != B.at(i)) { cout << "False\n"; getchar(); return 0; }
			}//�� ��򰡿� ��ġ�ϴ� ���ڰ� �ƴ� ���
			else if (Ismatch[j] == B.at(i)) { cout << "False\n"; getchar(); return 0; }
			else { Ismatch[i] = B.at(i); }
		}
	}	
	cout << "True\n";
	getchar();
	return 0;
}