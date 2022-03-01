#include <string>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;

bool sumbridge(vector<int> onbridge, int bridgeweight);

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> onbridge;

    reverse(truck_weights.begin(), truck_weights.end());
    // // temp에 트럭 무게들 역순으로 담기.
    // while (!truck_weights.empty())
    // {
    //     temp.push_back(truck_weights.back());
    //     truck_weights.pop_back();
    // }

    // temp의 트럭들을 다리 위로 하나씩 보내기

    do
    {
        if (onbridge.empty() || sumbridge(onbridge, weight)) {
            onbridge.push_back(truck_weights.back());
            truck_weights.pop_back();
            answer++;
        }
        
    } while (truck_weights.empty());
    
    
    return answer;
}

bool sumbridge(vector<int> onbridge, int bridgeweight) {
    int sum = 0;
    for (int i = 0; i < onbridge.size(); i++) {
        sum += onbridge[i];
    }
    if (sum > bridgeweight) {
        return false;
    }
    else {
        return true;
    }
    
}