#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	vector<int> card;
	int cardNum, goal;
	int start = 0, maxSum = -1;

	scanf("%d %d", &cardNum, &goal);
	for (int i = 0, tmp; i < cardNum; i++) {
		scanf("%d", &tmp);
		card.push_back(tmp);
	}
	sort(card.begin(), card.end(), greater<int>());
	while (card[start] >= goal)
		start++;
	for (int i = start; i < card.size() - 2; i++) {
		int cardSum = card[i];
		bool finish = false;
		for (int j = i + 1; j < card.size() - 1; j++) {
			cardSum += card[j];
			if (cardSum >= goal) {
				cardSum -= card[j];
				continue;
			}
			for (int k = j + 1; k < card.size(); k++) {
				cardSum += card[k];
				if (cardSum <= goal) {
					finish = true;
					if (maxSum < cardSum)
						maxSum = cardSum;
					break;
				}
				cardSum -= card[k];
			}
			cardSum -= card[j];
			if (finish)
				break;
		}
	}
	printf("%d\n", maxSum);
}
