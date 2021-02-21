#include <string>
#include <vector>
#include <algorithm>
#define HIT 1
#define MISS 5
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
   
    if(cacheSize == 0)
        return cities.size()*MISS;
    
    for(int i = 0; i < cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto itr = find(cache.begin(), cache.end(), cities[i]);
        
        //캐시히트
        if(itr == cache.end())
        {
            if(cache.size() == cacheSize)
                cache.erase(cache.begin());
            answer += MISS;
        }
        else //캐시미스
        {
            answer+= HIT;
            cache.erase(itr);
        }
        cache.push_back(cities[i]);
    }
    return answer;
}
