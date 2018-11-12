#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

constexpr int MAXN = 1005;

struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<VL> cap, flow, cost;
	vi seen;
	VL dist, pi;
	vector<pii> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap), seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;
		
		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while(!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			trav(i, ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			trav(i, red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll f1 = INF;
			for (int p,r,x = t; tie(p, r) = par[x], x != s; x = p) {
				f1 = min(f1, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			}
			totflow += f1;
			for (int p,r,x = t; tie(p, r) = par[x], x != s; x = p) {
				if (r) flow[p][x] += f1;
				else flow[x][p] -= f1;
			}
		}
		rep(i, 0, N) rep(j, 0, N) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int p, r, l;
	scanf(" %d %d %d", &p, &r, &l);
	
	MCMF mcmf(MAXN + 10);

	int left = MAXN + 1;
	int right = MAXN + 2;
	
	for (int i = 0; i < l; i++) {
		int e1, e2;
		scanf(" %d %d", &e1, &e2);
		e1 = e1 == -1 ? right : e1;
		e1 = e1 == -2 ? left : e1;
		e2 = e2 == -1 ? right : e2;
		e2 = e2 == -2 ? left : e2;
		mcmf.addEdge(e1, e2, 1, 1);
		mcmf.addEdge(e2, e1, 1, 1);
	}

	int source = MAXN + 3;
	mcmf.addEdge(source, left, p, 0);
	
	pair<ll, ll> ans = mcmf.maxflow(source, right);
	ll people = ans.first;
	if (people < p) {
		printf("%lld people left behind\n", p - people);
	} else {
		printf("%lld\n", ans.second);
	}
}
