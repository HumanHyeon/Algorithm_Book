long long gcd(int w, int h) {
	if (w > h) {
		int tmp = w;
		w = h;
		h = tmp;
	}
	while (w != 0) {
		int n = h % w;
		h = w;
		w = n;
	}
	return h;
}

long long solution(int w, int h) {
	long long g = gcd(w, h);
	return (long long)w * h - g * ((w / g) + (h / g) - 1);
}
