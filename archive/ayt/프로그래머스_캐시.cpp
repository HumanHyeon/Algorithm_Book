#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;

    if (cacheSize == 0) return cities.size() * 5;
    for (auto elem : cities) {
        transform(elem.begin(), elem.end(), elem.begin(), ::tolower);
        bool tf = false;
        int i;
        for (i = 0; i < dq.size(); ++i)
            if (elem == dq[i]) {
                tf = true;
                break;
            }
        if (tf) {
            dq.erase(dq.begin() + i);
            dq.push_front(elem);
            answer += 1;
        }
        else {
            if (cacheSize == dq.size()) dq.pop_back();
            dq.push_front(elem);
            answer += 5;
        }
    }

    return answer;
}
