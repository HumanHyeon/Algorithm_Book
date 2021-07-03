#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> table, vector<int> xy){
  int sum = 0;

  for(int i=xy[0]-1;i<xy[2];i++) {
    for(int j=xy[1]-1;j<xy[3];j++) {
      sum += table[i][j];
    }
  }

  return sum;
}

int main() {
  int N,M;
  vector<vector<int>> table;
  vector<vector<int>> xy;

  cin >> N >> M;

  for(int i=0;i<N;i++) {
    int* a = new int(N);
    vector<int> tmp;
    for(int j=0;j<N;j++)
      cin >> a[j];
    for(int j=0;j<N;j++) tmp.push_back(a[j]);
    table.push_back(tmp);
  }

  for(int i=0;i<M;i++) {
    int* a = new int(N);
    vector<int> tmp;
    for(int j=0;j<N;j++)
      cin >> a[j];
    for(int j=0;j<N;j++) xy.push_back(a[j]);
    xy.push_back(tmp);
  }

  for(auto elem : xy)
    cout << solution(table, elem) << endl;
}
