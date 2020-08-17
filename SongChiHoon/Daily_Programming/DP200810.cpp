#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    int temp, output;
    int i = 0;
    int *input = new int[10];

    do {
        cout << "input : ";
        cin >> temp;
        input[i] = temp;
        i++;
    } while (temp > 0);

    int count = 0;
    output = search(input, count);

    if (output < 0) {
        cout << "output : no_answer";
    }
    else {
        cout << "output : " << output;
    }
    delete[] input;

    return 0;
}

int search(int *input, int count) {
    if(input[count] == count) {
        return count;
    }
    else if(sizeof(input) < count) {
        return -1;
    }
    else {
        return(search(input, count++));
    }
}