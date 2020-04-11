#include <iostream>
using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
	/*bool finished = true;
	for (int i = 0; i < n; i++)
		if (!taken[i])
			finished = false;

	if (finished) return 1;
	int ret = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (!taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;*/

	int firstFree = -1;			//-1로 잡고 시작해서 모든 인원이 짝을 찾았는지 검사
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;		//짝을 못찾은 가장 빠른 인원 탐색 후 탈출
			break;
		}
	}

	if (firstFree == -1)	return 1;	//종료 시점 : 다 찾았으면 경우의 수는 1가지이니 종료
	int ret = 0;	//결과를 반환할 변수

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {
	int cycle;	cin >> cycle;
	int answer[10];

	for (int i = 0; i < cycle; i++) {
		int pair;
		bool reTaken[10] = { false , };
	
		cin >> n >> pair;		//학생 수, 친구 쌍의 수

		for (int j = 0; j < pair; j++) {	//친구 쌍 입력 받기
			int a, b;
			cin >> a >> b;
	
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		answer[i] = countPairings(reTaken);
	}
	
	for (int i = 0; i < cycle; i++)
		cout << answer[i] << endl;
}
