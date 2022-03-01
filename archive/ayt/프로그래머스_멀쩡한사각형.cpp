using namespace std;

long long gcd(int x,int y){
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}

long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    
    if(w==h)
        answer -= w;
    else if(h==1)
        answer -= w;
    else {
        answer -= w + h - gcd(w,h);
    }
    
    return answer;
}
