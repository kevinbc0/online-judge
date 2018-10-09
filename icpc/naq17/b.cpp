#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, int> pli;

constexpr int MAXN = 50003;

vector<pii> graph[MAXN];
int n;

static void shortest_paths(ll costs[MAXN], int s) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(make_pair(0L, s));
    for (int i = 0; i < MAXN; i++) {
        costs[i] = -1L;
    }
    while (pq.size() > 0) {
        pli frame = pq.top();
        pq.pop();
        int node = frame.second;
        ll cost = frame.first;
        if (costs[node] != -1 && cost >= costs[node]) {
            continue;
        }
        costs[node] = cost;
        for (pii next: graph[node]) {
            pq.push(make_pair(cost + (ll) next.second, next.first));
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int m, f, s, t;
    scanf(" %d %d %d %d %d", &n, &m, &f, &s, &t);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf(" %d %d %d", &u, &v, &c);
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }
    vector<pii> flights;
    for (int i = 0; i < f; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        flights.push_back(make_pair(u, v));
    }

    ll sps[MAXN];
    ll spt[MAXN];
    shortest_paths(sps, s);
    shortest_paths(spt, t);
    
    ll ans = sps[t] != -1 ? (ll) sps[t] : 1000000000000000007L;
    for (pii flight : flights) {
        if (sps[flight.first] != -1 && spt[flight.second] != -1) {
            ans = min(ans, sps[flight.first] + spt[flight.second]);
        }
    }
    printf("%lld\n", ans);
}
