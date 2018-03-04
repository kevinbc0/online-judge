#include <cstdio>
#include <iostream>

using namespace std;
using ll = long long;

constexpr ll MAX_N = 1005;

bool map[MAX_N][MAX_N];
int uf[MAX_N * MAX_N];
int uf_rank[MAX_N * MAX_N];
int r, c;

inline ll find(ll n) {
    if (uf[n] != n) {
        uf[n] = find(uf[n]);
    }

    return uf[n];
}

inline void do_union(ll a, ll b) {
    a = find(a);
    b = find(b);

    if (uf_rank[a] > uf_rank[b]) {
        uf[b] = a;
    } else if (uf_rank[b] > uf_rank[a]) {
        uf[a] = b;
    } else {
        uf[b] = a;
        uf_rank[a]++;
    }
}

inline void build_uf() {
    scanf("%d %d", &r, &c);
    for (ll i = 0; i < r; i++) {
        char str[c];
        scanf("%s", str);
        
        for (ll j = 0; j < c; j++) {
            map[i][j] = (str[j] == '1');
        }
    }

    for (ll i = 0; i < (r * 1000) + c; i++) {
        uf[i] = i;
    }

    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            if (j != 0 && map[i][j] == map[i][j - 1]) do_union(i * 1000 + j, i * 1000 + (j - 1));
            if (i != 0 && map[i][j] == map[i - 1][j]) do_union(i * 1000 + j, (i - 1) * 1000 + j);
        }
    }
}

inline void run_queries() {
    int q;
    scanf("%d", &q);

    for (int _ = 0; _ < q; _++) {
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        a--; b--; c--; d--;

        if (find(a * 1000 + b) == find(c * 1000 + d)) {
            printf(map[a][b] ? "decimal\n" : "binary\n");
        } else {
            printf("neither\n");
        }
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    build_uf();
    run_queries();
}
