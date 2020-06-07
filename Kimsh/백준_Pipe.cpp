//memorization 해야함
#include <iostream>
#include<vector>
using namespace std;

int n = 0, result = 0;
void carrying_pipe(int a, int b, int status = 0);
vector<vector<int>> house;
int main() {
	cout << "집의 크기 : ";
	cin >> n;
	int cache[n][n];
	for (int i = 0; i < n; i++) {
		vector<int> element(n);
		house.push_back(element);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
		}
	}
	
	carrying_pipe(0, 1);
	cout <<"result : "<< result<<"\n";
	getchar();
	return 0;
}
void carrying_pipe(int a, int b, int status) {
	cout <<"현재 : "<< a << ", " << b << "\n";
	if(cache[a][b]==0) return;
	int end_a, end_b = n;
	switch (status) {
	case 0:end_a = a; end_b = b + 1; break; //가로
	case 1:end_a = a + 1;  end_b = b; break;	//세로
	case 2:end_a = a + 1; end_b = b + 1; break;//대각선
	default: cout << "status 이상함\n"; break;
	}
	if (end_a > n-1 || end_b > n-1 || house[end_a][end_b] == 1) return;
	else if (end_a == n - 1 && end_b == n - 1) { cout << "찾음!\n"; result += 1; cache[a][b]=1; return; }
	else {
		if(end_b+1 <n && house[end_a][end_b+1] == 0)
		carrying_pipe(end_a, end_b, 0);
		if (end_a + 1 <n && house[end_a+1][end_b] == 0)
		carrying_pipe(end_a, end_b, 1);
		if(end_a + 1 <n&&end_b + 1 <n&&house[a+1][b] == 0 && house[a][b+1]==0 && house[end_a][end_b]==0)
		carrying_pipe(end_a, end_b, 2);
		return;
	}
	return; 
}
