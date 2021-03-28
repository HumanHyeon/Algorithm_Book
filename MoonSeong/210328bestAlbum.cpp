#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<pair<string, multimap<int, int, greater<int>>>> info;       //multimap(int plays, int index)
    
    for (int i = 0; i < genres.size(); i++) {
        int searchedGenreIndex = -1;
        for (int j = 0; j < info.size() && searchedGenreIndex == -1; j++)
            if (genres[i] == info[j].first) //isExistGenre
                searchedGenreIndex = j;
        
        if (searchedGenreIndex == -1) { //if genre is NOT exist
            multimap<int, int, greater<int>> tempMap;
            tempMap.insert(pair<int, int>(plays[i], i));
            info.push_back(pair<string, multimap<int, int, greater<int>>>(genres[i], tempMap));
            
        }
        else {  //is exist on info[searchedGenreIndex]
            info[searchedGenreIndex].second.insert(pair<int, int>(plays[i], i));
        }
    }
    
    //make order as genre:plays
    map<int, int, greater<int>> playOrder;  // <totalPlay, index>
    for (int i = 0; i < info.size(); i++) {
        int totalPlay = 0;
        for (multimap<int, int>::iterator it = info[i].second.begin(); it != info[i].second.end(); it++)
            totalPlay += it->first;
        playOrder.insert(pair<int, int>(totalPlay, i));
    }
    
    //include for order
    for (map<int, int>::iterator it = playOrder.begin(); it != playOrder.end(); it++) {
        //info[it->second] is selected
        int n = 0;
        for (multimap<int, int>::iterator it2 = info[it->second].second.begin(); it2 != info[it->second].second.end() && n < 2; it2++, n++)
            answer.push_back(it2->second);
            
    }
    
    return answer;
}
