#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//정수 곱셈
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);

	int aSize = a.size();
	int bSize = b.size();

	for (int i = 0; i < aSize; i++)
		for (int j = 0; j < bSize; j++)
			c[i + j] += a[i] * b[j];
	return c;
}

//a += b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	int originalASize = a.size();
	if (a.size() < b.size() + k)
		a.resize(b.size() + k);
	a.push_back(0);

	int aSize = a.size();
	for (int i = originalASize; i < aSize; i++)
		a[i] = 0;

	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i + k] += b[i];
}

// a -= b
// a>= b인 경우에만 사용 가능
void subFrom(vector<int>& a, const vector<int>& b)
{
	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i] -= b[i];
}

//카라츠바 곱셈
vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();

	if (an < bn)
		return karatsuba(b, a);
	if (an == 0 || bn == 0)
		return vector<int>();
	if (an <= 50)
		return multiply(a, b);
	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half)); //min<int> 이거 뭔지 모르겠다
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret(z2.size() + half * 2, 0);
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half * 2);
	return ret;
}

int hugs(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; ++i) A[i] = (members[i] == 'M');
	for (int i = 0; i < M; ++i) B[M - i - 1] = (fans[i] == 'M');

	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; ++i)
		if (C[i] == 0)
			++allHugs;
	return allHugs;
}

int main()
{
	int C;
	string m, f;
	int result[20];
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> m;
		cin >> f;
		result[i] = hugs(m, f);
	}
	for (int i = 0; i < C; i++) {
		cout << result[i] << endl;
	}
	return 0;
}
