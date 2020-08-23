#include <iostream>
using namespace std;

bool isfourpower(int input) {
    int editinput = input / 4;
    if (editinput % 4 != 0 || editinput < 4) {
        return false;
    }
    else if(editinput == 1) {
        return true;
    }
    return isfourpower(editinput);
}

int main() {
    int input;
    while (input <= 0) {
        cout << "input : ";
        cin >> input;
        if (input <= 0) {
            cout << "Input number must bigger than 0" << endl;
        }
    }
    if (isfourpower(input)) {
        cout << "Output : true";
    }
    else {
        cout << "Output : false";
    }
    
    return 0;
}