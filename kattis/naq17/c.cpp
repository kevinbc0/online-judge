#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2000005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    int coins[n];
    int dp[MAXN];
    for (int i = 0; i < n; i++) {
        scanf(" %d", &coins[i]);
    }
    int maxdp = coins[n - 1] + coins[n - 2];

    for (int i = 0; i < maxdp + 1; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    
    for (int i = 1; i < maxdp; i++) {
        int last_coin = 1;
        for (int coin : coins) {
            if (i - coin >= 0) {
                last_coin = coin;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[i] != dp[i - last_coin] + 1) {
            printf("non-canonical\n");
            return 0;
        }
    }

    printf("canonical\n");
}
