#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

void findCourse(string order, int size, string s, int index) {
    if (s.size() == size) {
        map<string, int>::iterator iter;
        iter = m.find(s);

        if (iter != m.end()) iter->second++;
        else m.insert(pair<string, int>(s, 1));

        return;
    }
    for (int i = index; i < order.size(); ++i)
        findCourse(order, size, s + order[i], i + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); ++i) {
        m.clear();

        for (int j = 0; j < orders.size(); ++j) {
            sort(orders[j].begin(), orders[j].end());
            if (course[i] <= orders[j].size())
                findCourse(orders[j], course[i], "", 0);
        }
        vector<pair<string, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);

        int result = v[0].second;

        if (!v.empty()) {
            if (result >= 2) {
                for (int i = 0; i < v.size(); ++i) {
                    if (v[i].second == result)
                        answer.push_back(v[i].first);
                    else break;
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

// 브루트포스
