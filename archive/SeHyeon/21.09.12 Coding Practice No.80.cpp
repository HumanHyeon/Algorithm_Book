https://programmers.co.kr/learn/courses/30/lessons/82612

#define SUB(X, Y) ((X) > (Y) ? 0 : (Y) - (X))

long long allPrice(int p, int c) {
	if (!c)
		return 0;
	return (p * c + allPrice(p, c - 1));
}

long long solution(int price, int money, int count) {
	return (SUB(money, allPrice(price, count)));
}
