#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define UNITS(A) (units == (A) ? (i == (A) ? false : true) : false)
using namespace std;

bool isDecimal(int num) {
    if (num < 2)    return false;
    for (int i = 2; i <= (int)sqrt(num); i++) 
        if (num % i == 0)    return false;
    return true;
}

bool canMake(string numbers, int num) {
    string strNum = to_string(num);

    for (int i = 0; i < strNum.size(); i++) {
        bool flag = false;
        for (int j = 0; j < numbers.size(); j++) 
            if (strNum[i] == numbers[j]) {
                strNum[i] = numbers[j] = ' ';
                flag = true;
                break;
        }
        if (!flag)   return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());
    
    for (int i = 2; i <= stoi(numbers); i++) {
        int units = i % 10;
        if (units == 0 || UNITS(2) || units == 4 || UNITS(5) || units == 6 || units == 8)    continue;
        if (!canMake(numbers, i)) continue;
        if (isDecimal(i)) {
            answer++;
        }
    }

    return answer;
}
