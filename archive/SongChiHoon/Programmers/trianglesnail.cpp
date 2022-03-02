#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    // Navigation
    bool down = true;
    bool up = false;

    //  Make double array
    int **temp = new int*[n];
    for(int i = 0; i < n; i++) {
        temp[i] = new int[n];
    }

    // Setting preset
    int endvalue = n * (n+1) / 2;
    int startvalue = 1;
    int row, column = 0;

    // input algorithm
    for(int input = 1; input != endvalue; input++) {

        // going down
        if(down == true && up == false) {
            temp[row][column] = input;
            row++;
            if(row == n || temp[row][column] != 0) {
                down = false;
                row--;
                column++;
            }
        }

        // going side
        else if(down == false && up == false) {
            temp[row][column] = input;
            column++;
            if(column == n || temp[row][column] != 0) {
                up = true;
                column--;
                column--;
                row--;
            }
        }

        // going up
        else if(down == false && up == true) {
            temp[row][column] = input;
            row--;
            column--;
            if(row == 0 || column == 0 || temp[row][column] != 0) {
                up = false;
                down = true;
                row++;
                row++;
                column++;
            }
        }
    }

    // Pushing answer
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            answer.push_back(temp[i][j]);
        }
    }

    return answer;
}