https://programmers.co.kr/learn/courses/30/lessons/17677

#include <algorithm>
#include <set>
using namespace std;

int solution(string str1, string str2) {
    multiset<string> s1, s2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    string separation = "";
    for (int i = 0; i < str1.size(); i++) {
        separation += str1[i];
        if (separation.size() == 2) {
            if (separation[0] >= 'a' && separation[0] <= 'z' && separation[1] >= 'a' && separation[1] <= 'z')
                s1.insert(separation);
            separation = str1[i];
        }
    }
    separation = "";
    for (int i = 0; i < str2.size(); i++) {
        separation += str2[i];
        if (separation.size() == 2) {
            if (separation[0] >= 'a' && separation[0] <= 'z' && separation[1] >= 'a' && separation[1] <= 'z')
                s2.insert(separation);
            separation = str2[i];
        }
    }

    if (s1.size() == 0 && s2.size() == 0)    return 65536;

    double unionSize = 0;
    multiset<string> tmpS1 = s1, tmpS2 = s2;
    for (auto fetchS1 : tmpS1) 
        if (tmpS2.find(fetchS1) != tmpS2.end()) 
            tmpS2.erase(tmpS2.find(fetchS1)), unionSize++;

    return (unionSize / ((double)s1.size() + (double)s2.size() - unionSize)) * 65536;
}
