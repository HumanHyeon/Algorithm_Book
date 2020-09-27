#include <string>
#include <vector>
#include <set>

using namespace std;

int cache[7];
int answer;
vector<int> v;
set<int> s;
int answer2 = 0;

void findPrime(int n) {
    bool tf = true;

    if (n==0 || n == 1) return;
    if (n==2) {
        ++answer2;
        return;
    }
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            tf = false;
            break;
        }
    }
    
    if (tf)
        ++answer2;
}


void dfs(int cnt, int n, string numbers) {
    if (cnt == n) {
        int ten = 1, tmp = 0;
        
        for (int i = v.size() - 1; i >= 0; --i) {
            tmp += v[i] * pow(10,j);
            ++j;
        }
        s.insert(tmp);
    }
    for (int i = 0; i < numbers.size(); ++i) {
        if (cache[i]) continue;
        cache[i] = true;
        v.push_back(numbers[i] - '0');
        dfs(cnt + 1, n, numbers);
        v.pop_back();
        cache[i] = false;
    }
}

int solution(string numbers) {
    for (int i = 1; i <= numbers.size(); ++i)
        dfs(0, i, numbers);
    for (auto elem : s)
        findPrime(elem);
    
    answer = answer2;

    return answer;
}
