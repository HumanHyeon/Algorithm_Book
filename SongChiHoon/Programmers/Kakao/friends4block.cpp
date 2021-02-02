#include <string>
#include <vector>

using namespace std;

class block
{
private:
    bool pop = false;
    
public:
    block(/* args */);
    ~block();
};

block::block(/* args */)
{
}

block::~block()
{
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<block> *playboard = new vector<block>;
    int count = 0;

    for (auto i : board) {
        for (auto j = 0; j < n; j++)
        {
            /* code */
        }
        
        playboard[count].letter = i;
        count++;
    }

    return answer;
}