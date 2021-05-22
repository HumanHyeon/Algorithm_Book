//https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>

using namespace std;

int solution(string s)
{
    int answer = 999999;

    int zip = 0;

    int count = 1;

    for (int i = 1; i <= s.size(); i++)//1에서 주어진 문자열의 길이 만큼
    {
        for (int j = 0; j < s.size(); j += i)
            if (j + i <= s.size())//현재 인덱스와 나누는 단위의 합이 전체 문자열 길이 이하
            {
                if (s.substr(j, i) == s.substr(j + i, i))
                    count++;

                else
                    if (count >= 10)//10개 이상의 중복일 경우
                    {
                        zip += to_string(count).size() + i;
                        count = 1;
                    }

                    else if (count == 1)//중복이 없을 경우
                        zip += i;

                    else//지금까지 중복된 수 + 문자열 길이
                    {
                        zip += i + 1;
                        count = 1;
                    }
            }

            else//현재 인덱스와 나누는 단위의 합이 범위를 벗어나기에 끝까지만 더함 
                zip += s.substr(j, i).size();

        if (zip < answer)
            answer = zip;

        zip = 0;
    }

    return answer;
}
