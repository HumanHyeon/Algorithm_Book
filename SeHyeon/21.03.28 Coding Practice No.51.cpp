https://programmers.co.kr/learn/courses/30/lessons/42579

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp2(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
    return a.second.first > b.second.first;
}

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    multimap<string, pair<int, int >> table;     //장르, (재생횟수, 고유번호))
    map<string, int> countPlays;
    vector<pair<string, int>> ranking;
    vector<pair<string, pair<int, int>>> sortTable;

    for (int i = 0; i < genres.size(); i++) {
            countPlays[genres[i]] += plays[i];  //재생횟수 횟수 증가
            pair<int, int> value = make_pair(plays[i], i);
            table.insert(pair<string, pair<int, int>>(genres[i], value));
    }
    
    copy(countPlays.begin(), countPlays.end(), back_inserter(ranking)); //전체 재생횟수를 정렬하기 위해 복사
    sort(ranking.begin(), ranking.end(), cmp);  //전체 재생횟수를 기준으로 정렬
    copy(table.begin(), table.end(), back_inserter(sortTable)); //재생횟수로 정렬하기 위해 복사
    sort(sortTable.begin(), sortTable.end(), cmp2); //재생횟수로 정렬
    
    table.clear();  //기존 테이블 초기화
    for (auto input : sortTable)    table.insert(pair<string, pair<int, int>>(input.first, make_pair(input.second.first, input.second.second)));    //테이블에 장르별 순위, 재생 횟수로 재입력

    for (auto fetchOrder : ranking) {
        string key = fetchOrder.first;
        int count = 0;
        for (auto iter = table.lower_bound(key); iter != table.upper_bound(key); iter++) {  //키에 해당되는 값들만 탐색
            if (count == 2)  break;
            answer.push_back(iter->second.second);
            count++;
        }
    }

    return answer;
}
