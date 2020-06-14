// 정렬된 정수 배열이 있습니다. 이 배열의 모든 원소들을 오른쪽으로 랜덤하게 Z번 이동하였습니다.

// 예를 들면 [1, 2, 3, 4, 5] -> [3, 4, 5, 1, 2].

// 이런 배열과 정수 K 가 주어지면, 배열안에 K가 존재하는지 찾으시오.

// 존재한다면 배열의 인덱스, 존재하지 않다면 -1 을 리턴하시오.

// 시간복잡도 제한 O(log N).



// input: [3, 4, 5, 1, 2], 4

// output: 1



// input: [2, 4, 5, 1], 3

// output: -1

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

list<int> movecontainer(list<int> container, int movesize)
{
    for (int i = 0; i < movesize; i++)
    {
        container.push_front(*container.end());
        container.pop_back();
    }
}

bool Imadefind(list<int> container, int move)
{
    for (int i = 0; i < sizeof(container); i++)
    {
        if (move == *container.begin())
            return true;
        else
            container.pop_front();
    }
    return false;
}

int main()
{
    int input;  int move;   bool answer;
    list<int> container;
    list<int>::iterator searchpoint;

    do
    {
        cin >> "inputarray(-1 = exit) : " >> input;
        if (input < 0)
        {
            break;
        }
        container.push_back(input);
    } while (1);

    cin >> "inputmovesize : " >> input;

    if(input > sizeof(container))
        move = input % sizeof(container);
    else
        move = input;

    container = movecontainer(container, move);

    answer = Imadefind(container, move);

    // searchpoint = find(container.begin(), container.end(), move);
    // if(searchpoint != container.end())
    //     answer = true;
    // else
    //     answer = false;

    cout << "output is " << answer;
}