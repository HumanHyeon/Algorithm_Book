#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calculate(long long a, long long b, char opr) {
    if (opr == '+')
        return a + b;
    else if (opr == '-')
        return a - b;
    else if (opr == '*')
        return a * b;
}

long long solution(string expression) {
    long long max_num = 0;
    vector <char> operator_list = { '*', '+', '-' };
    vector <long long> nums;
    vector <char> operators;
    string num = "";
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            nums.push_back(atoi(num.c_str()));
            num = "";
            operators.push_back(expression[i]);
        }
        else {
            num += expression[i];
        }
    }
    nums.push_back(atoi(num.c_str()));
    do {
        vector <long long>  temp_nums = nums;
        vector <char> temp_operators = operators;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < temp_operators.size(); j++) {
                if (temp_operators[j] == operator_list[i]) {
                    temp_nums[j] = calculate(temp_nums[j], temp_nums[j + 1], operator_list[i]);
                    temp_nums.erase(temp_nums.begin() + j + 1);
                    temp_operators.erase(temp_operators.begin() + j);
                    j--;
                }
            }
        }
        if (abs(temp_nums.front()) > max_num)
            max_num = abs(temp_nums.front());
    } while (next_permutation(operator_list.begin(), operator_list.end()));
    return max_num;
}