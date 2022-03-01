#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0;
    queue<int> now, length;
    
    while(1){
        int size = length.size();
        for(int i=0;i<size;++i){
            int l = length.front();
            length.pop();
            if(l==1){
                sum -= now.front();
                now.pop();
                continue;
            }
            length.push(l-1);
        }
        
        if(truck_weights.size()>0 && sum+truck_weights[0]<=weight){
            sum += truck_weights[0];
            now.push(truck_weights[0]);
            length.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        
        ++answer;
        
        if(truck_weights.empty() && now.empty())
            break;
    }

    return answer;
}
