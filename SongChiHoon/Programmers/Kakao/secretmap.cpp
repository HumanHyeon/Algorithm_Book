#include <string>
#include <vector>
 
using namespace std;
 
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> arr;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr1[i]%2 || arr2[i]%2){
                arr.push_back("#");
            }
            else{
                arr.push_back(" ");
            }
            arr1[i] = arr1[i]/2;
            arr2[i] = arr2[i]/2;
        }
        answer.push_back(arr[n-1]);
        for(int j = n-2; j >= 0; j--){
            answer[i] += arr[j];
        }
        arr.clear();
    }
    return answer;
}
