#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char upperchar(char c) {
    if ('a' < c && c < 'z') {
        return c - 32;
    }
    else {
        return c;
    }
}

vector<string> solution(vector<string> files) {

    vector<string> answer;

    string temp, tempnum, temphead, temptail;
    bool tail = false;
    int tempindex = 0;

    vector<string> HEAD;
    vector<int> NUMBER;
    vector<string> TAIL;

    for(auto it = files.begin(); it != files.end(); it++) {

        temp = *it;

        while(tempindex != temp.size()) {
            if('0' < temp[tempindex] && temp[tempindex] < '9') {
                tempnum += temp[tempindex];
                tail = true;
            }
            else if(tail == false) { temphead += toupper(temp[tempindex]); }
            else { temptail += temp[tempindex]; }
            tempindex++;
        }

        HEAD.push_back(temphead);
        NUMBER.push_back(stoi(tempnum));
        TAIL.push_back(temptail);

        tempindex = 0;
        tail = false;

        temphead.clear();
        tempnum.clear();
        temptail.clear();
    }

    vector<string> answerarray;

    for (int stand = 0; stand < files.size() - 1; stand++) {
        for (int comp = stand + 1; comp < files.size(); comp++) {
            if(HEAD[stand] > HEAD[comp]) {
                if(NUMBER[stand] > NUMBER[comp]) {
                    answerarray.push_back(files[comp]);
                }
            }
        }
        answerarray.push_back(files[stand]);
    }

    answer = answerarray;

    return answer;
}