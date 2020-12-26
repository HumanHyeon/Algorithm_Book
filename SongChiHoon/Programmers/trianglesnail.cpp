#include <string>
#include <vector>

using namespace std;

// vector<int> solution(int n) {
//     vector<int> answer;

//     //임시 배열 공간 할당
//     int size = 0;
//     for(int i = 1; i <= n; i++) { size += i; }
//     int *temp = new int[size];
    
//     //왼쪽 내려가는 대각선
//     int laststartpoint;
//     int num = 1;
//     for (int i = 0; num != n; num++) {
//         temp[i] = num;
//         i += num;
//         laststartpoint = i;
//     }

//     //삼각형의 밑변
//     int input = n;
//     for (int i = laststartpoint; i <= size; i++) { temp[i] = input++; }

//     //삼각형 우측 변

//     answer.assign(temp, temp + size);
//     return answer;
// }

vector<int> solution(int n) {
    vector<int> answer;

    // 방향 지시기
    bool down = true;
    bool up = false;

    int **temp = new int*[n];
    for(int i = 0; i < n; i++) {
        temp[i] = new int[n];
    }

    int endpoint = n;
    int endvalue;
    int startvalue = 1;
    int row, column = 0;

    for(int k = n; k > 0; k--) { endvalue += k; }

    for(int input = 1; input != endvalue; input++) {
        if(down == true && up == false) {
            temp[row][column] = input;
            row++;
            if(temp[row][column] != NULL || row == n) {
                down = false;
                row--;
                column++;
            }
        }
        else if(down == false && up == false) {
            temp[row][column] = input;
            column++;
            if(temp[row][column] != NULL || column == n) {
                up = true;
                column--;
                column--;
                row--;
            }

        }
        else if(down == false && up == true) {
            temp[row][column] = input;
            row--;
            column--;
            if(temp[row][column] != NULL || row == 0 || column == 0) {
                up = false;
                down = true;
                row++;
                row++;
            }
        }
    }

    // for(int start = 0; start < n; start++) {
    //     temp[start][0] = start + 1;
    // }

    // for(int start = 0; start < n; start++) {
    //     temp[n-1][start] = n+start;
    // }

    return answer;
}