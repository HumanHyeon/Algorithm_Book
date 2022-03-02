#include <string>
#include <vector>

using namespace std;

bool isIn(string shortStr, string longStr) {
        if (shortStr == longStr.substr(0, shortStr.length())) return true;
    return false;
}

bool solution(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size() - 1; i++)
        for (int j = i + 1; j < phone_book.size(); j++) {
            if ((phone_book[i].length() >= phone_book[j].length()) && isIn(phone_book[j], phone_book[i]))
                return false;
            if ((phone_book[j].length() >= phone_book[i].length()) && isIn(phone_book[i], phone_book[j]))
                return false;
        }
    
    return true;
}
