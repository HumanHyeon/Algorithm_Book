#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n;
    
    for(int i=0;i<prices.size();++i){
        n=0;
        if(i==prices.size()-1)
            n=0;
        for(int j=i+1;j<prices.size();++j){
            if(prices[i]<=prices[j])
                ++n;
            else{
                ++n;
                break;
            }
        }
        answer.push_back(n);
    }
    
    return answer;
}
