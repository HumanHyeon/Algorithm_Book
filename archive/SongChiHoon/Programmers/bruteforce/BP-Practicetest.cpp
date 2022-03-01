#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int MAX_NUM = answers.size();
    int biggest;
    vector<int> returns;
    int student[3] = { 0, 0, 0 };
    int temparray[5] = {3, 1, 2, 4, 5};

    // 1번 수포자 정답 비교
    for (int i = 0; i < MAX_NUM; i++) {
        if (answers[i] == (i % 5) + 1) { student[0]++; }
    }

    // 2번 수포자 정답 비교
    for (int i = 0; i < MAX_NUM; i++) {
        if (i % 2 == 0 && answers[i] == 2) { student[1]++; }
        else {
            if (i % 8 == 1 && answers[i] == 1) { student[1]++; }
            if (i % 8 == 3 && answers[i] == 3) { student[1]++; }
            if (i % 8 == 5 && answers[i] == 4) { student[1]++; }
            if (i % 8 == 7 && answers[i] == 5) { student[1]++; }
        }
    }

    // 3번 수포자 정답 비교
    for (int i = 0; i < MAX_NUM; i++) {
        int index = i % 10;
        if(answers[i] == temparray[index/2]) { student[2]++; }
    }

    // 정답 횟수 비교
    student[1] < student[2] ? biggest = student[2] : biggest = student[1];
    biggest < student[0] ? biggest = student[0] : biggest = biggest;

    for (int i = 0; i < 3; i++) {
        if (student[i] == biggest) { returns.push_back(i+1); }
    }
    return returns;
}