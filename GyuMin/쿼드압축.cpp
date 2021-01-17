//https://programmers.co.kr/learn/courses/30/lessons/68936#
#include <string>
#include <vector>

using namespace std;

static int count_0 = 0;

static int count_1 = 0;

void zip(vector<vector<int>> arr)
{
    bool can_zip = true;//압축 가능?

    int leng = arr[0].size();//한 변의 길이

    if (leng == 1) //하나만 있을 경우
        if (arr[0][0] == 0)
        {
            count_0++;
            return;
        }

        else
        {
            count_1++;
            return;
        }
   
    for(int i=0;i<leng;i++) //주어진 배열 전체 탐색
        for (int j = 0; j < leng; j++)
            if (arr[i][j] != arr[0][0])
            {
                can_zip = false;
                break;
            }
   
    if (can_zip) //압축 가능
        if (arr[0][0] == 0)
            count_0++;

        else
            count_1++;
   
    else//압축 불가능
    {
        vector<int> a;  
        vector<vector<int>> b;

        vector<int> c;
        vector<vector<int>> d;

        vector<int> e;
        vector<vector<int>> f;

        vector<int> g;
        vector<vector<int>> h;

        int half = leng / 2;

        for (int i = 0; i < half; i++)
        {
            for (int j = 0; j < half; j++)
            {
                a.push_back(arr[i][j]);
                c.push_back(arr[i + half][j]);
                e.push_back(arr[i][j + half]);
                g.push_back(arr[i + half][j + half]);
            }

            b.push_back(a);
            d.push_back(c);
            f.push_back(e);
            h.push_back(g);

            a.clear();
            c.clear();
            e.clear();
            g.clear();
        }

        zip(b);
        zip(d);
        zip(f);
        zip(h);
    }  
}

vector<int> solution(vector<vector<int>> a) 
{
    vector<int> answer;

    zip(a);

    answer.push_back(count_0);
    answer.push_back(count_1);

    return answer;
}
