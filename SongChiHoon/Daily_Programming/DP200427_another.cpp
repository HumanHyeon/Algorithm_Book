#include <iostream>
using namespace std;

bool check(int *input, int casenum) {
    int start = 0;
    int nextnum;
    for (int i = 0; i < casenum+1; i++)
    {
        nextnum = input[input[start]];
    }

    if (nextnum == input[start])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() {
    int casenum;

    cout << "Testcase : ";
    cin >> casenum;

    int *input = new int[casenum];

    cout << "Input : [";

    int i = 0;

    while (input == NULL)
    {
        cin >> input[i];
        i++;
    }

    cout << "Output : " << check(input, casenum);

}