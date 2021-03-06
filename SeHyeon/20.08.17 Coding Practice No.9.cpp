#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int count_weight(queue<int> bridge_truck) {
    int tmp = 0;
    while (!bridge_truck.empty()) {
        tmp += bridge_truck.front();
        bridge_truck.pop();
    }
    return tmp;
}

//int count_weight(queue<int> bridge_truck) {
//    if (bridge_truck.empty())    return 0;
//    int tmp = bridge_truck.front();
//    bridge_truck.pop();
//    return tmp + count_weight(bridge_truck);
//}

void all_plus_hour(queue<int>& bridge_hour) {
    int size = bridge_hour.size();
    while (size--) {
        int tmp = bridge_hour.front() + 1;
        bridge_hour.pop();
        bridge_hour.push(tmp);
    }
}

void process_pass_truck(queue<int>& bridge_hour, queue<int>& bridge_truck, int bridge_length){
    while (true) {
        if (bridge_truck.empty() || bridge_hour.empty()) break;
        if (bridge_hour.front() == bridge_length) {
            bridge_truck.pop();
            bridge_hour.pop();
        }
        else break;
    }
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int hour = 1, turn = 0;
    queue<int> bridge_truck, bridge_hour;

    while (turn != truck_weights.size()) {
        int bridge_weight = count_weight(bridge_truck);
        int next_weight = 0;    if (turn < truck_weights.size()) next_weight = truck_weights[turn];

        all_plus_hour(bridge_hour);
        process_pass_truck(bridge_hour, bridge_truck, bridge_length);

        if (bridge_weight + next_weight <= weight) {    //come in bridge
            bridge_truck.push(truck_weights[turn]);
            bridge_hour.push(1);
            if(turn != truck_weights.size()) turn++;
        }
        hour++;
    }
    while (!bridge_truck.empty() || !bridge_hour.empty()) {
        all_plus_hour(bridge_hour);
        process_pass_truck(bridge_hour, bridge_truck, bridge_length);
        hour++;
    }

    return hour;
}

int main() {
    vector<int> tw;
    int bl, w;
    //int arr[] = { 7, 4, 5, 6 };
    int arr[] = { 10,10,10,10,10,10,10,10,10,10 };
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        tw.push_back(arr[i]);
    bl = 100;
    w = 100;
    cout << solution(bl, w, tw) << endl;
}
