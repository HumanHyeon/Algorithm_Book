https://programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
	long long start = 1;
	long long end = *max_element(times.begin(), times.end()) * n;

	while (start <= end) {
		long long mid = (start + end) / 2;
		int count = 0;
		for (int i = 0; i < times.size(); i++) {
			count += (int)(mid / times[i]);
			if (count > n)
				end = mid - 1;
			if (count < n)
				start = mid + 1;
		}
	}
    return end;
}
