#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define INT_PAIR pair<int, int>
#define STR_INT_PAIR pair<string, int>

const bool compare (const STR_INT_PAIR & left, const STR_INT_PAIR & right) {
	return left.second > right.second;
}

int solution(int cacheSize, vector<string> cities) {

	int answer = 0;
	unordered_set<string> cache;
	vector<STR_INT_PAIR> cache_time;
	const INT_PAIR CACHE_VALUE = make_pair(1, 5);

	if (cacheSize == 0) { 
        return cities.size() * CACHE_VALUE.second; 
    }
	
	for (string city : cities) {

		std::transform(city.begin(), city.end(), city.begin(), ::tolower);

		if ( cache.find(city) != cache.end() ) {
			for (int index = 0; index != cacheSize; index++) {
				if (cache_time[index].first.compare(city) == 0) { cache_time[index].second = 0; break; }
			}
			answer += CACHE_VALUE.first;
		}
		else {
			const auto item = make_pair(city, 0);

			if (cache.size() < cacheSize) {
				answer += CACHE_VALUE.second;
			}
			else {
				std::sort(cache_time.begin(), cache_time.end(), compare);

				const auto item = *cache_time.begin();
				cache.erase(item.first);
				cache_time.erase(cache_time.begin());

				answer += CACHE_VALUE.second;
			}
			cache.insert(city);
			cache_time.push_back(item);
		}
		for (auto & item : cache_time) { 
            item.second++; 
        }
	}
	return answer;
}