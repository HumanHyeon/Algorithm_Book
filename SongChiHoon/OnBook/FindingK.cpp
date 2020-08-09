#include <iostream>
using namespace std;

void generate(int n, int m, string s) {
    if(n == 0 && m == 0) {
        cout << s << endl;
        return;
    }
    if(n > 0) generate(n-1, m, s + "-");
    if(m > 0) generate(n, m-1, s + "o");
}