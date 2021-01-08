#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> scoville, int K){
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto elem : scoville) pq.push(elem);
    
    while(pq.top() < K) {
        if(pq.size()==1) return -1;
        
        int x = pq.top();
        pq.pop();
        
        int y = pq.top();
        pq.pop();
        
        pq.push(x + 2*y);
        
        ++answer;
    }

    return answer;
}


/*#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K){
    int answer = 0;
    bool tf = false;

    for (int i = 0; i < scoville.size(); ++i) {
        sort(scoville.begin(), scoville.end());
        if (scoville[i] < K) {
            scoville[i + 1] = scoville[i] + 2 * scoville[i + 1];
            ++answer;
        }
        else {
            tf = true;
            break;
        }
    }

    if (!tf) return -1;

    return answer;
}*/
