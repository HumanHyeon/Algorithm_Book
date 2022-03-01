#include <string>
#include <vector>
#include <unordered_set>

#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

void makeString(string data, string charList, unordered_set<string>& dataSet) {
    if (data.length() == 8) {
        dataSet.insert(data);
        return;
    }
    
    for (int i = 0; i < charList.length(); i++)
        makeString(data + charList.substr(i, 1), charList.substr(0, i) + charList.substr(i+1, charList.length() - i - 1), dataSet);
}

int solution(int n, vector<string> data) {
    int answer = 0;
    
    string charList;
    unordered_set<string> dataSet;
    unordered_set<string>::iterator it;
    
    //init
    charList = "ACFJMNRT";
    makeString("", charList, dataSet);
    
    //check conditions
    for (int i = 0; i < n; i++) {
        //get data
        char A = data[i][0];
        char B = data[i][2];
        char oprtr = data[i][3];
        int opnd = data[i][4] + 1 - '0';
        //check conditions ALL dataset, and erase data which is false
        int prevIndex = 0;
        for (it = dataSet.begin(); it != dataSet.end();it++) {
            int indexOfA, indexOfB;
            int distance;
            //get index of A, B
            for (int j = 0; j < it->length(); j++) {
                if ((*it)[j] == A)
                    indexOfA = j;
                if ((*it)[j] == B)
                    indexOfB = j;
            }
            
            distance = (indexOfA > indexOfB) ? (indexOfA-indexOfB) : (indexOfB-indexOfA);
            
            //cout << "*it: " << *it;
            //cout << " / data: " << A << "~" << B << oprtr << opnd;
            //cout << " / indexOfA: " << indexOfA << ", indexOfB: " << indexOfB;
            //cout << " / distance: " << distance; 
            
            //erase
            switch(oprtr) {
                case '>':
                    if (distance <= opnd) {
                        dataSet.erase(it);
                        it = dataSet.begin();
                        //cout << " / >,erased" << endl;
                    }
                    break;
                case '<':
                    if (distance >= opnd) {
                        dataSet.erase(it);
                        it = dataSet.begin();
                        //cout << " / <,erased" << endl;
                    }
                    break;
                case '=':
                    if (distance != opnd) {
                        dataSet.erase(it);
                        it = dataSet.begin();
                        //cout << " / =,erased" << endl;
                    }
                    break;
            }
        }
    }
    
    answer = dataSet.size();
    return answer;
}
