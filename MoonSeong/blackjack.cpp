#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> cards;
    for (int i = 0; i < n; i++) {
        int card;
        scanf("%d", &card);
        cards.push_back(card);
    }

    sort(cards.begin(), cards.end());

    int res = 0;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                if (sum > m)
                    continue;
                else
                    res = sum > res ? sum : res;    
            }
    cout << res;
    
    return 0;
}
