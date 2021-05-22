//https://programmers.co.kr/learn/courses/30/lessons/62048#
using namespace std;

long long solution(int w, int h)
{
    long long answer = (long long)w * (long long)h;

    long long gcd;

    if (w == h)
        answer -= w;
        
    else
    {
        if (w > h)
            for (long long i = 1; i <= h; i++)
            {
                if (((long long)w % i == 0) && ((long long)h % i == 0))
                    gcd = i;
            }

        else
            for (long long i = 1; i <= w; i++)
            {
                if (((long long)w % i == 0) && ((long long)h % i == 0))
                    gcd = i;
            }

        answer -= gcd * ((w / gcd) + (h / gcd) - 1);
    }
    
    return answer;
}
