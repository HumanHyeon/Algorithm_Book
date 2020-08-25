#include <stack>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> stack;
    for (int i = 0; i < prices.size(); i++) {
        if (stack.empty()) {
            stack.push(make_pair(prices[i], i));
        }
        else if (stack.top().first <= prices[i]) {
            stack.push(make_pair(prices[i], i));
        }
        else {
            do {
                answer[stack.top().second] = i - stack.top().second;
                stack.pop();
                if (stack.empty())   break;
           } while (stack.top().first > prices[i]);
            stack.push(make_pair(prices[i], i));
        }
    }
    while (!stack.empty()) {
        answer[stack.top().second] = prices.size() - 1 - stack.top().second;
        stack.pop();
    }
    return answer;
}
