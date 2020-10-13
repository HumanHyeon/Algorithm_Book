#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> People1{ 1,2,3,4,5 }; //solution 함수안에서 사용할 수 있도록 전역
vector<int> People2{ 2,1,2,3,2,4,2,5 };
vector<int> People3{ 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == People1[i % 5]) sum1++;
        if (answers[i] == People2[i % 8]) sum2++;
        if (answers[i] == People3[i % 10]) sum3++;
    }

    /*int big = sum1;//max함수
    if(sum1 < sum2){
        big = sum2;
        if(sum2 < sum3){
            big = sum3;
        }
    }*/

    int big = max(sum1, max(sum2, sum3));

    if (big == sum1) answer.push_back(1);
    if (big == sum2) answer.push_back(2);
    if (big == sum3) answer.push_back(3);

    sort(answer.begin(), answer.end(), less<int>());
    return answer;
}