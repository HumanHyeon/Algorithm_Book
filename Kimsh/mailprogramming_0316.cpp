#include<iostream>
#include<string>
#include<array>
using namespace std;
#pragma warning (disable:4996)
//문자열 배열(string array)이 주어지면, 제일 긴 공통된 접두사(prefix)의 길이를 찾으시오.
/*
Input: [“apple”, “apps”, “ape”]
Input: [“hawaii”, “happy”]
Input: [“dog”, “dogs”, “doge”]
*/ 
#define SIZE 3


array <string, SIZE> arr = {"apple","apps","ape"};
array <int, SIZE> compare_result = {};

int Compare(int a , int b);

int main(void) {
	fill(compare_result.begin(), compare_result.end(), -1); //c++배열의 초기화 방법
	int final_result = 0 ;//최최최최종결과;;;

	for (int index1 = 0, index2 = 1,i = 0; index2 < SIZE; index2++) { //모든 경우의 수 비교
		if (index2 == index1) continue;
		compare_result[i] = Compare(index1, index2); i++;
		if (index2 == SIZE - 1 && index1 < SIZE - 2) {index1++; index2 = 0;}
	}

	for (int i = 0, j = 1; j < SIZE; j++) { //결과끼리 또 모든 경우의 수 비교
		if (i == j) continue;
		if (compare_result[j] == -1) {	final_result = compare_result[i]; break;	}
		else { final_result = compare_result[i] < compare_result[j] ? compare_result[i] : compare_result[j];}
		if (j == SIZE - 1 && i < SIZE - 2) { i++; j = 0; }
	}

	cout <<"결과 : "<< arr[0].substr(0, final_result)<<"\n";
	getchar();
	return 0;
}

int Compare(int a, int b) { //index a와 b의 문자열을 비교함 
	int result = 0; //몇 번째 글자까지 겹치는지 반환
	int repeat = arr[a].size() < arr[b].size() ? a : b; //글자 수가 더 작은 것 기준으로 비교
	for (int i = 1; i <= arr[repeat].size(); i++) {//안에 있는 글자 비교
		if (arr[a].substr(0, i) != arr[b].substr(0, i)) { return result; }
		else { result +=1; }
	}
	return result;
 }
