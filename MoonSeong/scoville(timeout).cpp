#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) { return a > b; }

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    while (true) {
        sort(scoville.begin(), scoville.end(), compare);
        if (scoville.back() > K) 
            break;
        if (scoville.size() < 2) {
            answer = -1;
            break;
        }
        
        int a = scoville.back(); scoville.pop_back();
        int b = scoville.back(); scoville.pop_back();
        scoville.push_back( a + b * 2 );
        answer++;
    }
    
    return answer;
}
