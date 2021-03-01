#include <string>
#include <vector>

using namespace std;


string Convert_To_N(int a, int b){
    string result = "";
    char list[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    while(a/b!=0){
        result= list[a%b]+result;
        a/=b;}
    
    result = list[a%b] +result;
    return result;
}



string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp="";
    
    for(int i=0;i<t*m;i++){
        tmp+=Convert_To_N(i,n);
    }
    int cnt = 0;
    for(int i = p-1;i<tmp.length();){
        answer += tmp.substr(i,1);
        if(cnt+1==t) break;
        cnt++;
        i+=m;
    }
    return answer;
    
    }
 
