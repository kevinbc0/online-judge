#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100005;

static void compute_dp(int dp[MAXN], int n, int counts[100]) {
    dp[0] = 0;
    for (int j = 1; j < MAXN; j++) {
        dp[j] = 101;
    }
    for (int i = 0; i < n; i++) {
        int copy_dp[MAXN];
        for (int i = 0; i < MAXN; i++) {
            copy_dp[i] = dp[i];
        }
        for (int j = 0; j < MAXN; j++) {
            if (j - counts[i] >= 0) {
                dp[j] = min(copy_dp[j], copy_dp[j - counts[i]] + 1);
            }
        }
    }
}

static void print_dp(int dp[MAXN], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h;
    scanf(" %d", &h);
    int hotdogs[100];
    for (int i = 0; i < h; i++) {
        scanf(" %d", &hotdogs[i]);
    }

    int b;
    scanf(" %d", &b);
    int buns[100];
    for (int i = 0; i < b; i++) {
        scanf(" %d", &buns[i]);
    }

    int hdp[MAXN];
    int bdp[MAXN];
    compute_dp(hdp, h, hotdogs);
    compute_dp(bdp, b, buns);
    int ans = 202;
    for (int i = 1; i < MAXN; i++) {
        int hotdog = hdp[i];
        int bun = bdp[i];
        if (hotdog != 101 && bun != 101) {
            ans = min(ans, hotdog + bun);
        }
    }
    if (ans > 200) {
        printf("impossible\n");
    } else {
        printf("%d\n", ans);
    }
}
