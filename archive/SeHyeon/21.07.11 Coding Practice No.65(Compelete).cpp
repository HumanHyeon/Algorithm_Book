#include <iostream>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	vector<int> card;
	int cardNum, goal;
	int maxSum = -1;

	scanf("%d %d", &cardNum, &goal);
	for (int i = 0, tmp; i < cardNum; i++) {
		scanf("%d", &tmp);
		card.push_back(tmp);
	}
	for (int i = 0; i < card.size() - 2; i++) {
		for (int j = i + 1; j < card.size() - 1; j++) {
			for (int k = j + 1; k < card.size(); k++) {
				int sum = card[i] + card[j] + card[k];
				
				if (sum > goal)
					continue;
				if (maxSum < sum)
					maxSum = sum;
			}
		}
	}
	printf("%d", maxSum);
}
