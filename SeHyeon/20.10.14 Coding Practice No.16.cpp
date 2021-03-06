#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define HEAD 0
#define NUMBER 1
using namespace std;

void sortByOrder(vector<string>& files, queue<int> order, int end, int start = 0) {
    vector<string> tmp = files;
    files.clear();
    for (int i = 0; i < tmp.size(); i++) 
        if (i >= start && i < end) {
            files.push_back(tmp[order.front()]);
            order.pop();
        }
        else    files.push_back(tmp[i]);
}

void order(vector<string>& files, int mode, int end, int start = 0) {
     queue<int> returnOrder;

    if (mode == HEAD) {
        vector<pair<string, int>> sortInfo;
        for (int i = start; i < end; i++) {
            string head = "";
            for (int j = 0; j < files[i].size(); j++) {
                if (files[i][j] >= '0' && files[i][j] <= '9')   break;
                head += files[i][j];
            }
            transform(head.begin(), head.end(), head.begin(), ::toupper);
            sortInfo.push_back(make_pair(head, i));
        }
        stable_sort(sortInfo.begin(), sortInfo.end());
        for (int i = 0; i < sortInfo.size(); i++) 
            returnOrder.push(sortInfo[i].second);
    }
    else if (mode == NUMBER){
        vector<pair<int, int>> sortInfo;
        for (int i = start; i < end; i++) {
            string number = "";
            for (int j = 0; j < files[i].size(); j++)
                if (number != "" && !(files[i][j] >= '0' && files[i][j] <= '9')) break;
                else if (files[i][j] >= '0' && files[i][j] <= '9')  number += files[i][j];
            sortInfo.push_back(make_pair(stoi(number), i));
        }
        stable_sort(sortInfo.begin(), sortInfo.end());
        for (int i = 0; i < sortInfo.size(); i++)   returnOrder.push(sortInfo[i].second);
    }

    sortByOrder(files, returnOrder, end, start);
}

vector<string> solution(vector<string> files) {
    order(files, NUMBER, files.size());
    order(files, HEAD, files.size());
    return files;
}
