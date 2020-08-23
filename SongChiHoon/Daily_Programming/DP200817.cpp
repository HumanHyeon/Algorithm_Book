#include <iostream>
using namespace std;

bool isfourpower(int input) {
    int editinput = input / 4;
    if (editinput % 4 != 0) {
        return false;
    }
    else {
        isfourpower(editinput);
        return true;
    }
}

int main() {
    int input;
    do {
        cout << "input : "; cin >> input;
        if (input <= 0) {
            cout << "Input number must bigger than 0" << endl;
            cout << "input : "; cin >> input;
        }
    } while (input == NULL);
    if (isfourpower(input)) {
        cout << "Output : true";
    }
    else {
        cout << "Output : false";
    }
    
    return 0;
}