// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// vector<int> solution(int N, vector<int> stages) {
//     vector<int> answer;
    
//     sort(stages.begin(), stages.end());

//     auto point = stages.begin();
//     int stage_index = 0;
//     int count = 0;
//     int temp = *stages.begin();
//     int users = stages.size();
//     int *failure = new int[N];

//     for(int i = 0; i < users; i++) {
//         if(temp == stages[i]) {
//             count++;
//         }
//         else {
//             failure[stage_index] = count;
//             temp = stages[i];
//             count++;
//         }
//     }

//     for (int i = 0; i < N; i++) {
//         cout << failure[i];
//     }
    
//     return answer;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    sort(stages.begin(), stages.end());
    
    int now = *stages.begin();
    int count = 0;
    int stage_index = 0;
    int *failure = new int[N];
    
    for(int i = 0; i < stages.size(); i++) {
        if(now == stages[i]) {
            count++;
        }
        else{
            failure[stage_index] = count;
            stage_index++;
            now = stages[i];
            count = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << stages[i] << " ";
    }
    
    return answer;
}