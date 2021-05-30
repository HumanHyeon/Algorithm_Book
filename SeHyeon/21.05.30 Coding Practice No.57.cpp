#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

//long long fx2(long long num) {
//    bitset<64> stdBs = num;
//    
//    for (long long i = num + 1; ; i++) {
//        bitset<64> cmpBs = i;
//        bitset<64> diffBs = (stdBs ^ cmpBs);
//
//        if (diffBs.count() <= 2 && diffBs.count() >= 1)
//            return i;
//    }
//}

long long fx(long long num) {
    bitset<64> stdBs = num;

    if (num % 2 == 0)
        stdBs.set(0);
    else
    {
        bool check = true;
        int firstFind;

        for (int i = 63; i >= 0; i--) {
            if (stdBs.test(i)) {
                firstFind = i;
                for (int j = i - 1; j >= 0; j--) {
                    if (!stdBs.test(j)) {
                        check = false;
                        break;
                    }
                }
                if (!check)
                    break;
            }
        }
        if (!check) {
            for (int i = 0; i < 64; i++) {
                if (!stdBs.test(i)) {
                    stdBs.set(i);
                    break;
                }
            }
        }
        else {
            stdBs.reset(firstFind);
            stdBs.set(firstFind + 1);
        }
    }
    return (long long)stdBs.to_ullong();

}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (auto fetch : numbers)
        answer.emplace_back(fx(fetch));
    return answer;
}

int main() {
    vector<long long> numbers = { 2, 7 };
    vector<long long> result = solution(numbers);
    
    for (auto tmp : result)
        cout << tmp << endl;
}
