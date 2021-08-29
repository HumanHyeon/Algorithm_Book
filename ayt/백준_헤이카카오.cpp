#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

void solution(int a, float d, float k) {
	float sum = a * d;
	vector<float> win;

	while (d <= 1) {
		win.push_back(d);
		d = d + d * k;
	}
	win.push_back(1);

	float tmp = 1;
	for (int i = 1; i < win.size(); i++) {
		tmp *= (1 - win[i-1]);
		sum += a * (i + 1) * tmp * win[i];
	}

	printf("%.7f", sum);
}

int main() {
	int a, d, k;
	cin >> a >> d >> k;

	solution(a, (float)d/100, (float)k/100);

	return 0;
}
