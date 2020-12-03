#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int tmp = 0;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=1;i<phone_book.size();++i){
        for(int j=0;j<phone_book[0].size();++j){
            if(phone_book[0][j]==phone_book[i][j])
                tmp++;
        }
        if(tmp == phone_book[0].size())
            answer = false;
        tmp = 0;
    }
    
    return answer;
}
