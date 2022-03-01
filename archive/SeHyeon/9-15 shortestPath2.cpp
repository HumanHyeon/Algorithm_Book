#include <iostream>
using namespace std;

int n, dist[MAX][MAX];
double cache[MAX][1 << MAX];

double shortestPath2(int here, int visited) {
	if (visited == (1 << n) - 1)	return dist[here][0];

	double& ret = cache[here][visited];
	if (ret >= 0)	return ret;
	ret = INF;

	for (int next = 0; next < n; ++next) {
		if (visited & (1 << next))	continue;
		double cand = dist[here][next] + shortestPath2(next, visited + (1 << next));
		ret = min(ret, cand);
	}
	return ret;
}
