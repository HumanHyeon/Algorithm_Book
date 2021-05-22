//https://programmers.co.kr/learn/courses/30/lessons/42626
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    int A, B;

    priority_queue<int, vector<int>, greater<int>> queue;

    for (int i = 0; i < scoville.size(); i++)
        queue.push(scoville[i]);

    while (queue.top() <= K)
    {
        A = queue.top();
        queue.pop();

        B = queue.top();
        queue.pop();

        queue.push(A + 2 * B);

        answer++;

        if ((queue.size() == 1) && (queue.top() < K))
            return -1;
    }

    return answer;
}
