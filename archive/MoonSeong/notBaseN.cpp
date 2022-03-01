#include <string>
#include <vector>
#include <cmath>

using namespace std;

int pow_int(int num, int exp) { return (int)pow((double)num, (double)exp); }

//123나라로 계산 후 '3'을 '4'로 바꿔줄것
string solution(int n) {
    string answer = "";
    
    int exp = 0;
    while (n > 0) {
        int res;
        
        // 3^(exp) 자리를 res로 채우고 남은 n이 3^(exp+1)의 배수인 res를 찾아야함
        for (res = 1; res <= 3; res++)
            if ( (n - res * pow_int(3, exp)) % pow_int(3, exp + 1) == 0 ) break;
        
        //정답 입력 처리부분
        string tmp = answer;
        switch(res) {
            case 1: answer = "1"; break;
            case 2: answer = "2"; break;
            case 3: answer = "4"; break;
            case 4: cout << "error"; break;
        }
        answer += tmp;
        n -= res * pow_int(3, exp);
        exp++;
    }
     
    return answer;
}
