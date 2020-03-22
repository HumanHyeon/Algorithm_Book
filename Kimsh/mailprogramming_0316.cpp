#include<iostream>
#include<string>
#include<array>
using namespace std;
#pragma warning (disable:4996)
//���ڿ� �迭(string array)�� �־�����, ���� �� ����� ���λ�(prefix)�� ���̸� ã���ÿ�.
/*
Input: [��apple��, ��apps��, ��ape��]
Input: [��hawaii��, ��happy��]
Input: [��dog��, ��dogs��, ��doge��]
*/ 
#define SIZE 3


array <string, SIZE> arr = {"apple","apps","ape"};
array <int, SIZE> compare_result = {};

int Compare(int a , int b);

int main(void) {
	fill(compare_result.begin(), compare_result.end(), -1); //c++�迭�� �ʱ�ȭ ���
	int final_result = 0 ;//�������������;;;

	for (int index1 = 0, index2 = 1,i = 0; index2 < SIZE; index2++) { //��� ����� �� ��
		if (index2 == index1) continue;
		compare_result[i] = Compare(index1, index2); i++;
		if (index2 == SIZE - 1 && index1 < SIZE - 2) {index1++; index2 = 0;}
	}

	for (int i = 0, j = 1; j < SIZE; j++) { //������� �� ��� ����� �� ��
		if (i == j) continue;
		if (compare_result[j] == -1) {	final_result = compare_result[i]; break;	}
		else { final_result = compare_result[i] < compare_result[j] ? compare_result[i] : compare_result[j];}
		if (j == SIZE - 1 && i < SIZE - 2) { i++; j = 0; }
	}

	cout <<"��� : "<< arr[0].substr(0, final_result)<<"\n";
	getchar();
	return 0;
}

int Compare(int a, int b) { //index a�� b�� ���ڿ��� ���� 
	int result = 0; //�� ��° ���ڱ��� ��ġ���� ��ȯ
	int repeat = arr[a].size() < arr[b].size() ? a : b; //���� ���� �� ���� �� �������� ��
	for (int i = 1; i <= arr[repeat].size(); i++) {//�ȿ� �ִ� ���� ��
		if (arr[a].substr(0, i) != arr[b].substr(0, i)) { return result; }
		else { result +=1; }
	}
	return result;
 }
