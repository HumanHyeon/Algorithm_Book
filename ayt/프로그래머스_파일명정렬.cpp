#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

bool sortTuple(tuple<string, string, int> a, tuple<string, string, int> b) {
    if (get<0>(a) == get<0>(b)) {
        if (get<1>(a) == get<1>(b))
            return get<2>(a) < get<2>(b);
        return stoi(get<1>(a)) < stoi(get<1>(b));
    }
    else return get<0>(a) < get<0>(b);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    string head;
    string number;
    string tail;
    bool ck = false;
    vector<tuple <string, string, int>> hnt;
    vector<string> tmp = files;

    for (int i = 0; i < tmp.size();++i) {
        while (1) {
            if (tmp[i].empty()) break;
            if (tmp[i].front() >= 48 && tmp[i].front() <= 57) {
                number.push_back(tmp[i].front());
                tmp[i].erase(tmp[i].begin());
                ck = true;
            }
            else {
                if (ck) break;
                head.push_back(tolower(tmp[i].front()));
                tmp[i].erase(tmp[i].begin());
            }
        }

        hnt.push_back(make_tuple(head, number, i));

        ck = false;
        head.clear();
        number.clear();
        tail.clear();
    }

    stable_sort(hnt.begin(), hnt.end(), sortTuple);

    string str = "";
    for (auto elem : hnt)
        answer.push_back(files[get<2>(elem)]);

    return answer;
}
