#include <string>
#include <map>

using namespace std;

void insertToMap(string str, map<string, int>& m) {
        map<string, int>::iterator it;
    for (int i = 0; i < str.length() - 1; i++) {
        //str[i] and str[i+1] is not A~Z
        if (str[i] < 'A' || str[i] > 'Z' || str[i+1] < 'A' || str[i+1] > 'Z')
            continue;
        
        it = m.find(str.substr(i, 2));
        if (it != m.end())
            (it->second)++;
        else
            m.insert(pair<string, int>(str.substr(i, 2), 1));  
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int> map1, map2;
    map<string, int>::iterator it;
    
    //Capitalize
    for (int i = 0; i < str1.length(); i++)
        if (str1[i] >= 'a' && str1[i] <= 'z')
            str1[i] = toupper(str1[i]);
    for (int i = 0; i < str2.length(); i++)
        if (str2[i] >= 'a' && str2[i] <= 'z')
            str2[i] = toupper(str2[i]);
    
    //make 2bytes-string and insert
    insertToMap(str1, map1);
    insertToMap(str2, map2);
    
    int a = 0, b = 0, t = 0;
    // n(t) = n(AnB) 
    // Jaccard similarity = n(t) / n(AuB)
    //  = n(t) / { (n(A) - n(t)) + (n(B) - n(t)) + n(t) }
    //  = n(t) / { n(A) + n(B) - n(t) }
    
    //get n(A), n(B)
    for (it = map1.begin(); it != map1.end(); it++)
        a += it->second;
    for (it = map2.begin(); it != map2.end(); it++)
        b += it->second;
    
    //get n(t)
    map<string, int>::iterator it2;
    for (it = map1.begin(); it != map1.end(); it++)
        for (it2 = map2.begin(); it2 != map2.end(); it2++)
            if (it->first == it2->first) {
                t += (it->second > it2->second ? it2->second : it->second);
                break;
            }
    
    //calc Jaccard similarity
    double j;
    if (a + b - t != 0)
        j = (double)t / (a + b - t);
    else 
        j = 1;
    answer = j * 65536;
    
    return answer;
}
