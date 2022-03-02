/*
table[] : 각 심사대의 남은시간

time = [7, 10]

[time]: [    ]
0: 7 10
7: 7 3
10: 4 10
14: 7 6
20: 1 10	or 20: 1 0
21: 0 9	or 21: 7 -1
28: -7 2	or 28: 0 -8
30: -9 0


최적이 아닌경우: 
모든 심사가 끝났을 때 (모든 심사대(table)가 0이하),

각각 심사시간(time[i]) < 심사대가 빈시간(abs(table[i])) 인 경우
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    vector<int> table(times.size(), 0);
    
    for (long long time = 0; ; time++) {
        
        //각 심사대 검사
        for (int i = 0; i < table.size(); i++) {
            //빈 경우
            if (table[i] == 0) {        
                //넣을 사람이 남은경우
                if (n > 0) {
                    //다른 최적의 심사대가 있는 경우
                    if () {

                    }
                    //다른 최적의 심사대가 없는 경우
                    else {
                        table[i] = times[i];
                    }
                }
            }
            //차있는 경우: 시간경과
            else if (table[i] > 0) {    
                table[i]--;
            }
        }
        
        //모든 심사대 시간감소
        for (int i = 0; i < table.size(); i++)
            table[i]--;
    }
    
    answer = time;
    return answer;
}
