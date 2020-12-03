#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string temp, comp;
    int smallsize = 987654321;
    int smallindex = 0;
    
    for (int i = 0; i < phone_book.size(); i++) {
        if(phone_book[i].size() < smallsize) {
            smallsize = phone_book[i].length();
            smallindex = i;
        }
    }
    
    temp = phone_book[smallindex];
    
    for(int i = 0; i < phone_book.size(); i++) {
        if (i != smallindex) {
            comp = phone_book[i].substr(0, smallsize);
            if(temp == comp) {
                return false;
            }
        }
    }
    return answer;
}