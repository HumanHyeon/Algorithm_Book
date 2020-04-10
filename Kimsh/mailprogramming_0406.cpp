#include<iostream>
using namespace std;
/*0�� 1�� ������� 2D ���� �迭�� �ֽ��ϴ�. 0�� ��ֹ��̰� 1�� �����϶�, �� ��ǥ�� �־�����, ù��° ��ǥ���� �ι�° ��ǥ���� ���� ����� �Ÿ��� ���Ͻÿ�. �� ��ǥ�� ��� ���ο��� ���۵ǰ� ��, ��, �Ʒ�, ���� �����̸� �밢�����δ� ������ �� �����ϴ�. ���� �� �� ���ٸ� -1�� �����Ͻÿ�.
����)
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
int arr[5][6] = { { 1, 0, 0, 1, 1, 0 },  // ���� ���� ���� �� 0 return �ؾ��� 
				  { 1, 0, 0, 1, 0, 0 },  // 1�� ã�ư�����
				  { 1, 1, 1, 1, 0, 0 },  //
				  { 1, 0, 0, 0, 0, 1 },  //
				  { 1, 1, 1, 1, 1, 1 } };//
int min_distance = INT32_MAX;
int start_a, start_b, arrive_a, arrive_b = 0;
int res(int distance, int a, int b);//�Ÿ��� ����ϴ� �Լ�. res�� ��������� distance�� return�մϴ�.

int main() {
	cout << "�������� ��ǥ �Է� : ";
	cin >> start_a >> start_b;
	cout << "�������� ��ǥ �Է� : ";
	cin >> arrive_a >> arrive_b;
	res(0,start_a, start_b);
	cout << "�ּ� �Ÿ� = " << min_distance<<"\n";
	getchar();
	getchar();
	return 0;
}
int res(int distance, int a, int b) //�������� �Ÿ�, ���� ��ǥ
{
	int tmp = distance;
	if ((a == arrive_a && b == arrive_b)) { min_distance = min_distance < tmp ? min_distance : tmp; return tmp; } //�������� ���� ��
	arr[a][b] = 0; // �Դ� ���� �ٽ� ������ �ʱ� ���� ������ġ
	if (b + 1 != 6 && arr[a][b + 1] != 0) res(tmp + 1, a, b + 1); //�� �������� ������ ����� �ʰ�, 1�� ��
	if (a + 1 != 5 && arr[a + 1][b] != 0) res(tmp + 1, a + 1, b); //�� �Ʒ����� ������ ����� �ʰ�, 1�� ��
	if (a - 1 >= 0 && arr[a - 1][b] != 0) res(tmp + 1, a - 1, b); //�� ������ ������ ����� �ʰ�, 1�� ��
	if (b - 1 >= 0 && arr[a][b - 1] != 0) res(tmp + 1, a, b - 1); //�� ������ ������ ����� �ʰ�, 1�� ��
	arr[a][b] = 1;

	return tmp;
}