#include <string>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int timecounter = 0;
    bool islanddown = false;
    queue<int> onbridge;
    vector<int> temp;
    reverse(truck_weights.begin(), truck_weights.end());
    // // temp에 트럭 무게들 역순으로 담기.
    // while (!truck_weights.empty())
    // {
    //     temp.push_back(truck_weights.back());
    //     truck_weights.pop_back();
    // }

    // temp의 트럭들을 다리 위로 하나씩 보내기
    do {
        int onbridge_trucksum = 0;
        if (islanddown) {
            islanddown = false;
            onbridge.pop();
        }
        for (int elements = onbridge.front(); elements < onbridge.back(); elements++) {
            onbridge_trucksum += elements;
        }
        if (onbridge_trucksum < weight && onbridge_trucksum + truck_weights.back() < weight) {
            onbridge.push(truck_weights.back());
            timecounter++;
            answer++;
        }
        else {
            answer++;
        }
        timecounter = ++timecounter % bridge_length;
        if (timecounter == 0) {
            islanddown = true;
        }
    } while (!truck_weights.empty() && !onbridge.empty());
    return answer;
}