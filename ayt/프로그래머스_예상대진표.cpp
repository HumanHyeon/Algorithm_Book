using namespace std;

int solution(int n, int a, int b){
    int answer = 1;

    if(a>b) {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    
    while(1){
        if(a+1 == b && a%2) break;
        
        a = a%2 ? a/2+1 : a/2;
        b = b%2 ? b/2+1 : b/2;
        
        answer++;
    }

    return answer;
}
