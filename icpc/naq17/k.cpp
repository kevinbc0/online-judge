#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
constexpr ll MAXN = 10005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    ll t1, t2;
    scanf(" %d %d %lld %lld", &n, &k, &t1, &t2);
    ll measurements[MAXN];
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &measurements[i]);
    }
    pll intervals[MAXN];
    for (int i = 0; i < k; i++) {
        ll start, end;
        scanf(" %lld %lld", &start, &end);
        intervals[i] = make_pair(start, end);
    }

    vector<pll> failure_intervals;
    for (int i = 0; i < k; i++) {
        pll interval = intervals[i];
        ll start = interval.first;
        ll end = interval.second;
        for (int j = 0; j < n; j++) {
            ll new_start = start - measurements[j];
            ll new_end = end - measurements[j];
            if (new_start > t2 || new_end < t1) {
                continue;
            }
            if (new_start < t1) {
                new_start = t1;
            }
            if (new_end > t2) {
                new_end = t2;
            }
            failure_intervals.push_back(make_pair(new_start, new_end));
        }
    }

    sort(failure_intervals.begin(), failure_intervals.end());
    if (failure_intervals.size() == 0) {
        printf("1.0\n");
        return 0;
    }
    pll current_interval = failure_intervals[0];
    vector<pll> final_intervals;
    for (int i = 1; i < failure_intervals.size(); i++) {
        pll next_interval = failure_intervals[i];
        ll next_start = next_interval.first;
        ll next_end = next_interval.second;
        ll ci_end = current_interval.second;
        if (ci_end < next_start) {
            final_intervals.push_back(current_interval);
            current_interval = next_interval;
        } else if (ci_end < next_end) {
            current_interval.second = next_end;
        }
    }
    final_intervals.push_back(current_interval);
    ll total_length = 0;
    for (int i = 0; i < final_intervals.size(); i++) {
        total_length += final_intervals[i].second - final_intervals[i].first;
    }
    printf("%Lf\n", (long double) ((t2 - t1) - total_length) / (t2 - t1));
}
