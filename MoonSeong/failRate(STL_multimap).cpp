#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int failed[502];    // 1~501
    int approach[502];
    
    multimap<double, int, greater<double>> failRate;
    multimap<double, int>::iterator it;
    
    //init
    for (int i = 1; i < N + 2; i++) {
        failed[i] = 0;
        approach[i] = 0;
    }
    
    //init failed[] & approach[]
    for (int i = 0; i < stages.size(); i++) {
        failed[stages[i]]++;
        for (int j = 1; j <= stages[i]; j++)
            approach[j]++;
    }
    
    //calc failRate
    for (int i = 1; i < N + 1; i++)
        if (approach[i] == 0) 
            failRate.insert({0, i});
        else 
            failRate.insert( {(double)failed[i]/approach[i], i} );
    
    //failRate -> answer
    for (it = failRate.begin(); it != failRate.end(); it++)
        answer.push_back(it->second);

    return answer;
}
