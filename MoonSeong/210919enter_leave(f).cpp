#include <string>
#include <vector>
#include <set>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(1000, 0);
    
    set<int> room;
    
    int enterCount = 0;
    int leaveCount = 0;
    
    while (enterCount < enter.size() || leaveCount < leave.size()) {
        if (room.find(leave[leaveCount]) != room.end()) {   //나갈차례가 방에 없다 = 입실
            //입실
            room.insert(enter[enterCount]);
            enterCount++;
            //answer 갱신
            for (auto it = room.begin(); it != room.end(); it++)
                if (answer[*it] < room.size())
                    answer[*it] = room.size();
                //answer[*it] = answer[*it] > room.size() ? answer[*it] : room.size();
            
        }
        else {  //나갈차례가 방에 있다 = 퇴실
            room.erase(leave[leaveCount]);
            leaveCount++;
        }
    }
    
    return answer;
}

int main(void) {
    vector<int> enter = {1, 3, 2};
    vector<int> leave = {1, 2, 3};

    vector<int> answer = solution(enter, leave);

    for (int i = 0; i < answer.size(); i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    

    return 0;
}
