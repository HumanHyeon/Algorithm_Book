#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow; //�Ѱ���

    for (int y = 3; y < sum; y++)//x(����),y(����) -- �ּұ��� 3
    {
        if (sum % y == 0) //������ ���� ���̿� ������������
        {
            int x = sum / y; //���� ���̸� ���� �� ����
            if (((y - 2) * (x - 2)) == yellow) //�׵θ��� ����
            {
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }
    }

    return answer;
}