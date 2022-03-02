#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

map<int, int> table;

void calcRun(string s, unordered_set<string> key) {
    int length = s.size();
    vector<int> which;
    for (const auto cmpStr : key) {
                            cout << cmpStr << endl;
        int n = 0;
        while (s.find(cmpStr, n) != string::npos) {
            n = s.find(cmpStr, n);
            which.push_back(n);
            n++;
        }
        if (which.size() == 1) {
            which.clear();
            continue;
        }

        cout << "<which>" << endl;
        for (auto tmp : which) cout << "\t" << tmp;
        putchar('\n');
        int bIndex = -1, count;
        for (auto tmp : which) {    //tmp는 인덱스
            if (bIndex == -1) { //처음이면
                bIndex = tmp;
                count = 1;
                continue;
            }
            cout << bIndex << endl;

            if (bIndex + cmpStr.size() == tmp) {    //이어지면
                cout << "test" << endl;

                if (count == 1) {   //기존꺼가 1개밖에 없으면 압축x
                    bIndex = tmp;
                    count++;
                }
                else {  //2개 이상 존재 시 이므로 앞껏들 앞축과정
                    int frontIndex = cmpStr.size() * count;
                    int backIndex = tmp + cmpStr.size();
                    cout << frontIndex << " " << backIndex << endl;
                    s.erase(frontIndex, backIndex);
                    count = 1;
                    bIndex = tmp;
                }
            }
            else {  //이어지지 않으면
                bIndex = tmp;
                count = 1;
            }
            //cout << tmp << endl;

        }
        cout << s << endl;
        which.clear();
    }




    cout << "끝!!!\t\t\t\t끝" << endl;
}

void calc (string s, int n) {
    unordered_set<string> key;
    for (int i = 0; i < s.size(); i++) {
        string tmp = "";
        bool flag = true;
        int count = 0;
        for (int j = i; j < s.size(); j++) {
            if (i + (n - 1) >= s.size()) {
                flag = false;
                break;
            }
            if (count++ == n)    break;
            tmp += s[j];
        }
        if (flag) key.insert(tmp);
    }
    calcRun(s, key);
}

int solution(string s) {
    int answer = 0;

    for (int i = 1; i <= s.size() / 2; i++)
        calc(s, i);


    return answer;
}

int main() {
    string s = "abaabbc";
    //calc(s, 2);
    solution(s);
}
