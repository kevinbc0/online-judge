#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size();

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ll inf = 1LL << 61;
const int MAXN = 102;
const int MAXG = 200004;
inline void floydWarshall(ll m[MAXN][MAXN], int n) {
    rep(i,0,n) m[i][i] = min(m[i][i], {});
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) {
			auto newDist = max(m[i][k] + m[k][j], -inf);
			m[i][j] = min(m[i][j], newDist);
		}
	rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin.exceptions(cin.failbit);

	int g, k, r;
	scanf(" %d %d %d", &g, &k, &r);

	ll graph[MAXN][MAXN];
	for (int i = 0; i < k; i++) {
		// printf("SZIE %d\n", graph[i].size());
		for (int j = 0; j < k; j++) {
			if (i == j) {
				graph[i][j] = 0;
			} else {
				graph[i][j] = inf;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		int a, b;
		ll t;
		scanf(" %d %d %lld", &a, &b, &t);
		graph[a - 1][b - 1] = t;
		graph[b - 1][a - 1] = t;
	}
	floydWarshall(graph, k);
	pair<pll, pil> gigs[MAXG];
	gigs[0] = make_pair(make_pair(0L, 0L), make_pair(0, 0));
	for (int i = 1; i <= g; i++) {
		int v;
		ll s, e, m;
		scanf(" %d %lld %lld %lld", &v, &s, &e, &m);
		gigs[i] = make_pair(make_pair(e, s), make_pair(v - 1, m));
	}
	
	sort(gigs, &gigs[g + 1]);
	vector<int> node_gigs[MAXN];
	for (int i = 0; i < g; i++) {
		pair<pll, pil> gig = gigs[i];
		node_gigs[gig.second.first].push_back(i);
	}

	ll dp[MAXG];
	int last[MAXN];
	for (int i = 0; i < k; i++) {
		last[i] = -1;
	}
    last[0] = 0;
    for (int i = 1; i <= g; i++) {
        dp[i] = -inf;
    }
	dp[0] = 0;
	for (int i = 1; i <= g; i++) {
		pair<pll, pil> gig = gigs[i];
		ll end = gig.first.first;
		ll start = gig.first.second;
		int node = gig.second.first;
		dp[i] = (last[node] == -1) ? -inf : dp[last[node]];
		last[node] = i;
        if (graph[node][0] == inf) {
            continue;
        }
		ll cost = gig.second.second;
		for (int j = 0; j < k; j++) {
			if (graph[node][j] == inf) {
				continue;	
			}
			ll latest_end = start - graph[node][j];	
            if (latest_end < 0) {
                continue;
            }
			// binary search to find latest gig at node j that ends before latest_end
			vector<int> ngigs = node_gigs[j];
			int lo = -1, hi = ngigs.size();
			while (lo + 1 < hi) {
				int mid = lo + (hi - lo) / 2;
				if (mid == -1) {
					break;
				}
				if (gigs[ngigs[mid]].first.first > latest_end) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
			if (lo == -1) {
                if (j == 0 and latest_end >= 0) {
                    dp[i] = max(dp[i], cost);
                }
				continue;
			}
			int index = ngigs[lo];
            ll newdp = dp[index] == -inf ? -inf : dp[index] + cost;
			dp[i] = max(dp[i], newdp); 
		}
	}

	ll ans = 0;
	for (int i = 0; i <= g; i++) {
		//printf("%d %lld\n", i, dp[i]);
		ans = max(ans, dp[i]);
	}
	printf("%lld\n", ans);
}
