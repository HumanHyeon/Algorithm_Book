#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void stringFriends(string& friends, int start, int end, vector<string>& data, int& answer) {
    if (start == end) {
        bool tf = false;
        for (auto d : data) {
            int distance = friends.find(d[0]) - friends.find(d[2]);
            int num = d[4] - '0';

            switch (d[3]) {
            case '=':
                if (abs(distance) - 1 == num) tf = true;
                else tf = false;
                break;
            case '<':
                if (abs(distance) - 1 < num) tf = true;
                else tf = false;
                break;
            case '>':
                if (abs(distance) - 1 > num) tf = true;
                else tf = false;
                break;
            }
            if (!tf) break;
        }
        if (tf) ++answer;
    }
    else {
        for (int i = start; i <= end; ++i) {
            swap(friends[start], friends[i]);
            stringFriends(friends, start + 1, end, data, answer);
            swap(friends[start], friends[i]);
        }
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    
    stringFriends(friends, 0, friends.size() - 1, data, answer);

    return answer;
}
