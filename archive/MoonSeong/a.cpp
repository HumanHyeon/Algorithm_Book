#include <iostream>

using namespace std;

int main(void) {
    string input;
    cin >> input;
    
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        int n = 0;
        //get n
        n += ch / 100;
        ch -= 100 * (ch / 100);
        n += ch / 10;
        ch -= 10 * (ch / 10);
        n += ch;
        //print for n
        while (n-- > 0)
            cout << input[i];
        cout << endl;
    }

    return 0;
}
