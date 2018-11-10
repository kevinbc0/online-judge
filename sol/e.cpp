#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int MAXN = 2003;

double distance (int x, int y, int x1, int y1) {
	return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	scanf(" %d", &n);
	int xs[MAXN];
	int ys[MAXN];
	int rs[MAXN];
	for (int i = 0; i < n; i++) {
		int x, y, r;
		scanf(" %d %d %d", &x, &y, &r);
		xs[i] = x;
		ys[i] = y;
		rs[i] = r;
	}

	vector<vector<pair<int, double>>> graph(MAXN);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			double d = distance(xs[i], ys[i], xs[j], ys[j]) - rs[i] - rs[j];
			graph[i].push_back(make_pair(j, d));
		}
	}

	// prims
	bool seen[MAXN];
	for (int i = 0; i < n; i++) {
		seen[i] = false;
	}
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push(make_pair(0.0, 0));
	double total = 0.0;
	while (pq.size() > 0) {
		pair<double, int> frame = pq.top();
		pq.pop();
		double cost = frame.first;
		int node = frame.second;
		if (seen[node]) {
			continue;
		}
		seen[node] = true;
		total += cost;
		for (pair<int, double> next : graph[node]) {
			int nnode = next.first;
			double cost = next.second;
			pq.push(make_pair(cost, nnode));
		}
	}

	printf("%lf\n", total);
}
