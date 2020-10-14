#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int n = brown+yellow;;                        //가로, 세로
    
    for(int i=1;i*i<=n;++i){
        if(n%i==0 && yellow==(i-2)*(n/i-2)){          //brown + yellow == h * v
            answer.push_back(n/i);                    //yellow == (h - 2) * (v - 2)
            answer.push_back(i);
        }
    }
    
    return answer;
}
