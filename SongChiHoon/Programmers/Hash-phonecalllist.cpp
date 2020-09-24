#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int small = 1000;
    int smallindex;
    for (int i = 0; i < phone_book.size(); ++i) {
    	if (phone_book[i].size() < small) {
    		small = phone_book.size();
    		smallindex = i;
    	}
    }
    string smallword = phone_book[smallindex];
    phone_book.erase(smallindex, smallindex);
    for (int i = 0; i < phone_book.size(); ++i) {
    	if (phone_book[i].compare(0, smallword.size(), smallword) == 0) {
    		answer = false;
    	}
    }

    return answer;
}