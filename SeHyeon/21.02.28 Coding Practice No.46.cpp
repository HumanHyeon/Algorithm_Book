#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

stack<char> operator_table;
stack<string> operand_table;
long long answer = 0;

//void division(string ex, vector<char>& oper) {
//    if (ex.find('+') != string::npos || ex.find('-') != string::npos || ex.find('*') != string::npos) {
//        for (int i = 0; i < oper.size(); i++) {
//            if (ex.find(oper[i]) != string::npos) {
//                division(ex.substr(0, ex.find(oper[i])), oper);
//                division(ex.substr(ex.find(oper[i]) + 1), oper);
//                operator_table.push(oper[i]);
//            }
//        }
//    }
//    else operand_table.push(ex);
//}

long long cal(long long num1, long long num2, char op) {
    if (op == '+')   return num1 + num2;
    if (op == '-')   return num1 - num2;
    if (op == '*')   return num1 * num2;
    return -987654321;
}

void calcpriority(string expression, vector<char> oper) {
    long long result = 0;

    for (auto fetchOper : oper) {
        while (true) {
            if (expression.find(fetchOper, 1) == string::npos) {
                cout << "\tbreak" << endl;  break;
            }
            string merge_front = "", merge_back = "", operand1 = "", operand2 = "";
            int which = expression.find(fetchOper, 1);
            char op = expression[which];
            long long middle_result;

            for (int i = which - 1; i >= 0; i--) {
                if (i == 0) {
                    operand1 = expression.substr(0, which);
                    break;
                }
                if (!(expression[i] >= '0' && expression[i] <= '9')) {
                    /*if (i == 1) {
                        operand1 = expression.substr(0, which);
                        break;
                    }*/
                    if (expression[i - 1] >= '0' && expression[i - 1] <= '9') {
                        operand1 = expression.substr(i + 1, which - i - 1);
                        merge_front = expression.substr(0, i + 1);
                        break;
                    }
                    else {
                        operand1 = expression.substr(i, which - i);
                        merge_front = expression.substr(0, i);
                        break;
                    }
                }
            }
            
            if (!(expression[which + 1] >= '0' && expression[which + 1] <= '9')) {
                for (int i = which + 2; i < expression.size(); i++) {
                    if (i == expression.size() - 1) {
                        operand2 = expression.substr(which + 1);
                        break;
                    }
                    if (!(expression[i] >= '0' && expression[i] <= '9')) {
                        operand2 = expression.substr(which + 1, i - which - 1);
                        merge_back = expression.substr(i);
                        break;
                    }
                }
            }
            else
            {
                for (int i = which + 1; i < expression.size(); i++) {
                    if (i == expression.size() - 1) {
                        operand2 = expression.substr(which + 1);
                        break;
                    }
                    if (!(expression[i] >= '0' && expression[i] <= '9')) {
                        operand2 = expression.substr(which + 1, i - which - 1);
                        merge_back = expression.substr(i);
                        break;
                    }
                }
            }
            cout << merge_front << " \t<<<>>>\t " << merge_back << endl;
            cout << operand1 << " " << operand2 << "  => ";
            string mid = to_string(cal(stoll(operand1), stoll(operand2), op));
            cout << mid << endl;
            expression = merge_front + mid + merge_back;
            cout << "[[[  " << expression << "  ]]]" << endl;
        }
        cout << endl;
    }
    if (answer < stoi(expression)) answer = stoi(expression);
}

long long solution(string expression) {
    vector<vector<char>> priority = {
        { '+', '-', '*' },
        { '+', '*', '-' },
        { '-', '+', '*' },
        { '-', '*', '+' },
        { '*', '+', '-' },
        { '*', '-', '+' }
    };


    for (auto fetch : priority) {
        calcpriority(expression, fetch);
    }

    return answer;
}

int main() {
    string t = "100-200*300-500+20";
    
    cout << solution(t) << endl;
    cout << endl;
    /*string t1 = t.substr(0, t.find('+'));
    //string t2 = t.substr(t.find('+') + 1);

    //cout << t1 << endl;
    //cout << t2 << endl;*/
    //vector<char> oper = { '+', '-', '*' };
    //division(t, oper);

    //while (!operator_table.empty()) {
    //    char out = operator_table.top();
    //    operator_table.pop();
    //    cout << out << endl;
    //}
    //cout << endl;
    //while (!operand_table.empty()) {
    //    string out = operand_table.top();
    //    operand_table.pop();
    //    cout << out << endl;
    //}

    //string t = "100+200-500";
    //int which = 7;
    //int i = 3;

    //string tmp = t.substr(i + 1, which - i - 1);
    //cout << tmp << endl;

    //string merge = t.substr(0, i + 1);
    //cout << merge << endl;
}
