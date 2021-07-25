#include <iostream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int rolling(int size, int pos, vector<int>& field) {
    size += field[pos];
    return size;
}

int throwing(int size, int pos, vector<int>& field) {
    size = (size / 2) + field[pos+1];
    return size;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> field(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &field[i]);
    
    //start
    int rollExpectedVal;
    int throwExpectedVal;
    int size = 1;
    int pos = 0;
    int time = 1;
    while (time > 1 && )
}
