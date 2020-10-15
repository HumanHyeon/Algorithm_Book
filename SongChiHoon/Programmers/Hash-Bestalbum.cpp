#include <string>
#include <vector>
#include <map>

using namespace std;

template<template <typename> class P = std::greater >
struct compare_pair_second {
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>&left, const std::pair<T1, T2>&right) {
        return P<T2>()(left.second, right.second);
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genrescollection;
    vector<pair<int, int>> ordercollectionfirst;
    vector<pair<int, int>> ordercollectionsecond; 
    int first, second;
    string firstgenre, secondgenre;
    for (int i = 0; i < genres.size(); i++) {
    	genrescollection[genres[i]] += plays[i];
    }
    for (auto& it = genrescollection.begin(); it != genrescollection.end(); it++) {
    	if (it->second > first) {
    		second = first;
    		first = it->second;
    		firstgenre = it->first;
    	}
    	else if(it->second > second) {
    		second = it->second;
    		secondgenre = it->first;
    	}
    }
    int index = 0;
    for (auto& it = genrescollection.begin(); it != genrescollection.end(); it++) {
    	if (it->first == firstgenre) {
    		ordercollectionfirst.emplace_back(make_pair(index, it->second));
    	}
    	if (it->first == secondgenre) {
    		ordercollectionsecond.emplace_back(make_pair(index, it->second));
    	}
    	index++;
    }
    sort(ordercollectionfirst.begin(); ordercollectionfirst.end(), compare_pair_second<greater>());
    sort(ordercollectionsecond.begin(); ordercollectionsecond.end(); compare_pair_second<greater>());

    for (auto& it = ordercollectionfirst.begin(); it != ordercollectionfirst.end(); it++) {
    	answer.push_back(it->first);
    }
    for (auto& it = ordercollectionsecond.begin(); it != ordercollectionsecond.end(); it++) {
    	answer.push_back(it->first);
    }
    return answer;
}