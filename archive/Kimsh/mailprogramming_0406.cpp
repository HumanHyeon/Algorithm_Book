#include<iostream>
using namespace std;
/*0과 1로 만들어진 2D 정수 배열이 있습니다. 0은 장애물이고 1은 도로일때, 두 좌표가 주어지면, 첫번째 좌표에서 두번째 좌표까지 가장 가까운 거리를 구하시오. 두 좌표는 모두 도로에서 시작되고 좌, 우, 아래, 위로 움직이며 대각선으로는 움직일 수 없습니다. 만약 갈 수 없다면 -1을 리턴하시오.
예제)
Input:
{{1, 0, 0, 1, 1, 0},
{1, 0, 0, 1, 0, 0},
{1, 1, 1, 1, 0, 0},
{1, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1}}

Start: (0, 0)
Finish: (0, 4)
Output: 8
*/
int arr[5][6] = { { 1, 0, 0, 1, 1, 0 },  // 가는 길이 없을 때 -1 return 해야함 
				  { 1, 0, 0, 1, 0, 0 },  // 1을 찾아가야함
				  { 1, 1, 1, 1, 0, 0 },  //
				  { 1, 0, 0, 0, 0, 1 },  //
				  { 1, 1, 1, 1, 1, 1 } };//
int min_distance = INT32_MAX;
int start_a, start_b, arrive_a, arrive_b = 0;
int res(int distance, int a, int b);//거리를 계산하는 함수. res는 현재까지의 distance를 return합니다.

int main() {
	cout << "시작지점 좌표 입력 : ";
	cin >> start_a >> start_b;
	cout << "도착지점 좌표 입력 : ";
	cin >> arrive_a >> arrive_b;
	res(0,start_a, start_b);
	if (min_distance == INT32_MAX) min_distance = -1;
	cout << "최소 거리 = " << min_distance<<"\n";
	getchar();
	getchar();
	return 0;
}
int res(int distance, int a, int b) //여지껏의 거리, 현재 좌표
{
	int tmp = distance;
	if (arr[a][b] == 0 || arr[arrive_a][arrive_b] == 0) return tmp;
	if ((a == arrive_a && b == arrive_b)&&arr[arrive_a][arrive_b]!=0) { min_distance = min_distance < tmp ? min_distance : tmp; return tmp; } //도착지점 도달 시
	arr[a][b] = 0; // 왔던 길을 다시 지나지 않기 위한 안전장치
	if (b + 1 != 6 && arr[a][b + 1] != 0) res(tmp + 1, a, b + 1); //내 오른쪽이 범위를 벗어나지 않고, 1일 때
	if (a + 1 != 5 && arr[a + 1][b] != 0) res(tmp + 1, a + 1, b); //내 아래쪽이 범위를 벗어나지 않고, 1일 때
	if (a - 1 >= 0 && arr[a - 1][b] != 0) res(tmp + 1, a - 1, b); //내 위쪽이 범위를 벗어나지 않고, 1일 때
	if (b - 1 >= 0 && arr[a][b - 1] != 0) res(tmp + 1, a, b - 1); //내 왼쪽이 범위를 벗어나지 않고, 1일 때
	arr[a][b] = 1;

	return tmp;
}
