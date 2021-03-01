#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isExistBigger(queue<int> prior, int cmp) {
    while (!prior.empty()) {
        int extract = prior.front();
        if (extract > cmp)   return true;
        prior.pop();
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int print = 0;
    queue<int> printer;

    for (vector<int>::iterator tmp = priorities.begin(); tmp != priorities.end(); tmp++)
        printer.push(*tmp);

    while (!printer.empty()) {
        int extract = printer.front();
        printer.pop();

        if (isExistBigger(printer, extract)) {
            printer.push(extract);
            if (location == 0) {
                location = printer.size();
            }
        }
        else {  //complete print
            print++;
            if (location == 0) {
                answer = print;
                break;
            }
        }
        --location;
    }

    return answer;
}

int main() {
    int arr[] = { 2, 1, 3, 2 };
    //int arr[] = { 1, 1, 9, 1, 1, 1};
    int location = 2;
    vector<int> v;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        v.push_back(arr[i]);
    
    cout << solution(v, location) << endl;
}
