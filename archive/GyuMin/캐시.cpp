//https://programmers.co.kr/learn/courses/30/lessons/17680
#include <string>
#include <vector>
#include <algorithm>

#define MISS 5
#define HIT 1

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0)
        return MISS * cities.size();

    int answer = 0;

    vector<string> cache;

    for (int i = 0; i < cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        int j = 0;

        if (cache.size() == 0)
        {
            answer += MISS;
            cache.push_back(cities[i]);
            continue;
        }

        for (j = 0; j < cache.size(); j++)
            if (cities[i] == cache[j])
            {
                answer += HIT;
                cache.erase(cache.begin() + j);
                cache.push_back(cities[i]);
                break;
            }

        if (j == cache.size())
        {
            if (cache.size() == cacheSize)
                cache.erase(cache.begin());

            answer += MISS;

            cache.push_back(cities[i]);
        }
    }

    return answer;
}
