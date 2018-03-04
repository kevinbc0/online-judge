#include <cstdio>
#include <iostream>

using namespace std;

using ll = long long;

constexpr ll MOD = 1000000007;

inline void solve(string s) {
    ll sum = 0;
    ll acc = 0;
    ll count = 1;

    for (char& c : s) {
        if (c == '0') {
            sum = (sum + acc) % MOD;
        } else if (c == '1') {
            acc = (acc + count) % MOD;
        } else {
            sum = ((sum + sum) % MOD + acc) % MOD;
            acc = ((acc + acc) % MOD + count) % MOD;
            count = (count + count) % MOD;
        }
    }

    printf("%lld\n", sum);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    getline(cin, s);
    solve(s);
}
