#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cache;

    if (cacheSize == 0) return cities.size() * 5;
    for (auto fetch : cities) {
        transform(fetch.begin(), fetch.end(), fetch.begin(), ::tolower);
        if (find(cache.begin(), cache.end(), fetch) != cache.end()) {
            answer += 1;
            cache.erase(find(cache.begin(), cache.end(), fetch));
            cache.push_back(fetch);
        }
        else {
            if (cache.size() >= cacheSize) cache.pop_front();
            cache.push_back(fetch);
            answer += 5;
        }
    }

    return answer;
}
