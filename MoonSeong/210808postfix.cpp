#include <iostream>
#include <string>
#pragma warning (disable:4996)

using namespace std;

string toPostfix(string exp, string operand1, string operand2, string operator1) {
    int i = 0;
    while (exp[i] != NULL) {
        switch(exp[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
                operator1 = exp[i];
                break;
            case '(':
            case ')':
                
            default:
        }




        i++;
    }
}


int main(void) {
    string exp;
    string answer;
    scanf("%s", &exp);

    answer = toPostfix(exp, NULL, NULL, NULL);

}
