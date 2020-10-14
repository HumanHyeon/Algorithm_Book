#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow; //총개수

    for (int y = 3; y < sum; y++)//x(가로),y(세로) -- 최소길이 3
    {
        if (sum % y == 0) //총합이 세로 길이와 나눠떨어지면
        {
            int x = sum / y; //가로 길이를 구할 수 있음
            if (((y - 2) * (x - 2)) == yellow) //테두리줄 제외
            {
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }
    }

    return answer;
}