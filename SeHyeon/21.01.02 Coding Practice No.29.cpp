#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 1;
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    
    /*for (auto iter = scoville.begin(); iter != scoville.end(); iter++)
        pq.push(*iter);*/

    if (pq.top() >= k) return 0;    
    for (; ; answer++) {
        if (pq.empty()) return -1;
        int first = pq.top();   pq.pop();
        if (pq.empty()) return -1;
        int second = pq.top();  pq.pop();
        pq.push(first + second * 2);
        if (pq.top() >= k) break;
    }

    return answer;
}
