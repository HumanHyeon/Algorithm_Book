#include <string>
#include <vector>
#include <set>

using namespace std;

bool cmp(string left, string right) {
    int n;  //abcdefghij&10, length()=13, indexOf'&'=11
    for (int i = 0; i < left.length(); i++) 
        if (left[i] == '&')
            n = stoi(left.substr(i+1, left.length() - i));
    
    if (left[n] == right[n]) {
        for (int i = 0; i < left.length(); i++) 
            if (left[i] != right[i])
                return left[i] < right[i];
    }
    else {
        return left[n] < right[n];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    bool(*fn_pt)(string, string) = cmp;
    multiset<string, bool(*)(string, string)> strList(fn_pt);
    multiset<string>::iterator it;
    
    for (int i = 0; i < strings.size(); i++)
        strList.insert(strings[i] + '&' + to_string(n));
    
    for (it = strList.begin(); it != strList.end(); it++) {
        int x = it->length();
        while ((*it)[x] != '&') 
            x--;
        answer.push_back(it->substr(0, x)); 
    }
    return answer;
}
