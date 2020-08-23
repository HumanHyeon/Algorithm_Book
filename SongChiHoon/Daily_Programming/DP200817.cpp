#include <iostream>
using namespace std;

bool isfourpower(int input) {

    int editinput = input / 4;

    if (editinput % 4 != 0) {
        return false;
    }
    else if(editinput == 1) {
        return true;
    }

    return isfourpower(editinput);
}

int main() {
    int input;

    cin >> "input : " >> input;

    while (input <= 0) {
        cout << "Input number must bigger than 0" << endl;
        cin >> "input : " >> input;
    }

    if (isfourpower(input)) {
        cout << "Output : true";
    }
    else {
        cout << "Output : false";
    }
    
    return 0;
}