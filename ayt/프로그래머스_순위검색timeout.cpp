#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (int i = 0; i < query.size(); ++i) {
        int cnt = 0;
        int loc = 0;
        string qLang = query[i].substr(loc, query[i].find(" "));
        loc = query[i].find(" ") + 5;
        string qEnd = query[i].substr(loc, query[i].find(" ", loc) - loc);
        loc = query[i].find(" ", loc) + 5;
        string qCareer = query[i].substr(loc, query[i].find(" ", loc) - loc);
        loc = query[i].find(" ", loc) + 5;
        string qFood = query[i].substr(loc, query[i].find(" ", loc) - loc);
        loc = query[i].find(" ", loc) + 1;
        string qScore = query[i].substr(loc, query[i].find(" ", loc) - loc);

        for (int j = 0; j < info.size(); ++j) {
            loc = 0;
            string iLang = info[j].substr(loc, info[j].find(" "));
            if (qLang != iLang && qLang != "-") continue;

            loc = info[j].find(" ") + 1;
            string iEnd = info[j].substr(loc, info[j].find(" ", loc) - loc);
            if (qEnd != iEnd && qEnd != "-") continue;

            loc = info[j].find(" ", loc) + 1;
            string iCareer = info[j].substr(loc, info[j].find(" ", loc) - loc);
            if (qCareer != iCareer && qCareer != "-") continue;

            loc = info[j].find(" ", loc) + 1;
            string iFood = info[j].substr(loc, info[j].find(" ", loc) - loc);
            if (qFood != iFood && qFood != "-") continue;

            loc = info[j].find(" ",loc) + 1;
            string iScore = info[j].substr(loc, info[j].find(" ", loc) - loc);
            if (stoi(qScore) <= stoi(iScore)) ++cnt;
        }
        answer.push_back(cnt);
    }

    return answer;
}
