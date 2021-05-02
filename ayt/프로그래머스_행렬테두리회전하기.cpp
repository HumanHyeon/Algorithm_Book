#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> hr;
    vector<int> tmphr;
    
    int count = 1;
    for (int i = 1; i <= rows; ++i) {
        vector<int> tmphr;
 
        for (int j = 1; j <= columns; ++j) {
            tmphr.push_back(count);
            ++count;
        }
        hr.push_back(tmphr);
    }
    
    for(auto elem : queries){
        int startY = elem[0], startX = elem[1];
        int endY = elem[2], endX = elem[3];
        vector<vector<int>> tmp(hr);
        int i,j;
        
        for(i=startX;i<endX;++i) {
            hr[startY][i+1] = tmp[startY][i];
        }
        
        for(j=startY;j<endY;++j) {
            hr[j+1][i+1] = tmp[j][i+1];
        }
        
        for(i=endX;i>=startX;--i) {
            hr[j+1][i-1] = tmp[j+1][i]
        }
        
        for(j=endY;j>=startY;--j) {
            hr[j-1][i-1] = tmp[j][i-1]
        }
    }
    
    
    return answer;
}
