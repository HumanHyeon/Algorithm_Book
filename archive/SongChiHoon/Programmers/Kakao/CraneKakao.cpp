#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<int> collecting;

    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    
    for(row = board.begin(); row != board.end(); row++)
    {
        for(col = row->begin(); col != row->end(); col++)
        {
            if(*col == 0)
            {
                continue;
            }
            else
            {
                collecting.push_back(*col);
                if(col == --col)
                {
                    answer++;
                    *col = 0;
                }
            }
        }
    }
    return answer;
}
