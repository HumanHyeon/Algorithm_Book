#include <iostream>
using namespace std;

int n, m;                        //분류기가 반환한 문장, 단어 번호로 변환되어 있음
int R[100];                      //T[i][j] = i 단어 이후에 j 단어가 나올 확률의 로그값
double T[501][501];              //M[i][j] = i 단어가 j 단어로 분류될 확률의 로그 값
double M[501][501];
int choice[102][502];
double cache[102][502];          //i로 초기화

//Q[segment] 이후를 채워서 얻을 수 있는 최대 g() 곱의 로그 값을 반환
//Q[segment-1] == previousMatch라고 가정
double recognize(int segment, int previousMatch) {
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = -1e200;                //log(0) = 음의 무한대에 해당하는 값
	int& choose = choice[segment][previousMatch];        //R[segment]에 대응되는 단어를 찾음
	for (int thisMatch = 0; thisMatch < m; ++thisMatch) {
		//g(thisMatch) = T(previousMatch, thisMatch) * M(thisMatch, R[segment])
		double cand = T[previousMatch][thisMatch]
			+ M[thisMatch][R[segment]]
			+ recognize(segment + 1, thisMatch);
		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

//입력받은 단어들의 목록
string corpus[501];
string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];
	if (segment < n - 1)
		ret = ret + " " + reconstruct(segment + 1, choose);
	return ret;
}

int main() {


	return 0;
}
