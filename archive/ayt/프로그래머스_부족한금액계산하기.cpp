using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 0;
    
    for(int i=1;i<=count;i++)
        sum += (price*i);
    
    answer = (money-sum<0) ? (money-sum)*-1 : 0;

    return answer;
}
