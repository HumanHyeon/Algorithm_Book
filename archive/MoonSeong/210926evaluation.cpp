#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a < b;
}


string solution(vector<vector<int>> scores_t) {
    string answer = "";
    
    vector<vector<int>> scores = scores_t;
    for (int i = 0; i < scores_t.size(); i++)
        for (int j = 0; j < scores_t[i].size(); j++)
            scores[i][j] = scores_t[j][i];

    for (int i = 0; i < scores.size(); i++) {
        double average = 0;
        int grade = 0; 
        int myScore = scores[i][i];
        int sum = 0;
        sort(scores[i].begin(), scores[i].end(), compare);
        for (int j = 0; j < scores[i].size(); j++)
            sum += scores[i][j];

        if ((scores[i][0] == myScore && scores[i][1] != myScore) || (scores[i][scores[i].size()-1] == myScore && scores[i][scores[i].size()-2] != myScore))
            average = (double)(sum - myScore) / (scores[i].size() - 1);
        else
            average = (double)sum / scores[i].size();

        grade = average / 10;

        switch(grade) {
            case 10:
            case 9:
                answer += "A";
                break;
            case 8:
                answer += "B";
                break;
            case 7:
                answer += "C";
                break;
            case 6:
            case 5:
                answer += "D";
                break;
            default:
                answer += "F";
        }
    }
    
    return answer;
}
