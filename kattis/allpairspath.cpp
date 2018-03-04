#include <limits>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

#define MAX_N 150

constexpr ll INF = numeric_limits<ll>::max();
constexpr ll N_INF = numeric_limits<ll>::lowest();

int n, q;
ll weights[MAX_N][MAX_N];
ll apsp[MAX_N][MAX_N];

void read_graph() {
    int e;
    scanf("%d %d %d", &n, &e, &q);

    if (n + q + e == 0) {
        exit(0);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            weights[i][j] = i == j ? 0 : INF;
        }
    }
    
    for (int i = 0; i < e; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        weights[u][v] = min(weights[u][v], w);
    }

    copy(&weights[0][0], &weights[0][0] + MAX_N * MAX_N, &apsp[0][0]);
}

void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ll sum = apsp[i][k] == INF || apsp[k][j] == INF ? INF : apsp[i][k] + apsp[k][j];
                apsp[i][j] = min(apsp[i][j], sum);
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (apsp[i][k] != INF && apsp[k][j] != INF && apsp[k][k] < 0) {
                    apsp[i][j] = N_INF;
                }
            }
        }
    }
}

void run_queries() {
    for (int _ = 0; _ < q; _++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (apsp[u][v] == INF) printf("Impossible\n");
        else if (apsp[u][v] == N_INF) printf("-Infinity\n");
        else printf("%lld\n", apsp[u][v]);
    }
}

int main(int argc, char* argv[]) {
    while (true) {
        read_graph();
        floyd_warshall();
        run_queries();
        printf("\n");
    }
}
