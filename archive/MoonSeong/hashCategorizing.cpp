#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    vector<string> clothesName;
    vector<int> numOfClothes;
    
    for (int i = 0; i < clothes.size(); i++) {
        bool isClothesExist;
        int clothesIndex;
        // 이미 있는 종류인지 검사
        for (int j = 0; j < clothesName.size(); j++) 
            if (clothes[i][1] == clothesName[j]) {
                isClothesExist = true;
                clothesIndex = j;
                break;
            }
            else 
                isClothesExist = false;
        
        //이미 있는 종류라면 카운트, 없다면 clothesName에 추가
        if (isClothesExist) {
            numOfClothes[clothesIndex]++;
        }
        else {
            clothesName.push_back(clothes[i][1]);
            numOfClothes.push_back(1);
        }
    }
    
    //계산: (각 종류의 옷의 개수 + 1) 을 전부 곱한 값의 -1 (아예 안 입는 경우)
    for (int i = 0; i < numOfClothes.size(); i++) 
        answer *= numOfClothes[i] + 1;
    answer -= 1;
    
    return answer;
}
