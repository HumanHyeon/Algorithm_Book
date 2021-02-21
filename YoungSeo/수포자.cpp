#include <vector>
#include <cmath>
using namespace std;
vector<int> solution(vector<int> answers) { 
vector<int> answer;
vector<int> answer1 {1, 2, 3, 4, 5};
vector<int> answer2 {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> answer3 {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; 
int count1 = 0;
int count2 = 0;
int count3 = 0; 
int size = answers.size();
for(int i = 0; i < size; ++i) {
    int i1=i%5;
    int i2=i%8;
    int i3=i%10;
    
    if(answers[i] == answer1[i1]) count1++;
    if(answers[i] == answer2[i2]) count2++; 
    if(answers[i] == answer3[i3]) count3++; }
    int maxCount = max(count1, max(count2, count3));
    if(maxCount == count1) 
    answer.push_back(1); 
    if(maxCount == count2) answer.push_back(2);
    if(maxCount == count3) answer.push_back(3);
    return answer;
    }
