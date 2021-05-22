#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n>0){   //n이 0이될때까지 반복
        if(n%3==0){ //3으로 나눈 나머지=0
            answer.insert(0,"4");
            n=n/3 - 1;
        }
        else{  //3으로 나눈 나머지가 0이 아닐때
            answer.insert(0,to_string(n%3));
            n=n/3;
        }
    }
    return answer;
}
