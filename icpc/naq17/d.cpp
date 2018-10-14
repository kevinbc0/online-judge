#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
constexpr int MAXN = 16;

int n;
double m;
pii locs[MAXN];
int times[MAXN];

static double distance(pii a, pii b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

static bool works(double v) {
    int permutation[n];
    for (int i = 0; i < n; i++) {
        permutation[i] = i;
    }
    pii location = make_pair(0, 0);
    double time = 0.0;
    do {
        bool worked = true;
        for (int i = 0; i < n; i++) {
            pii next_loc = locs[permutation[i]];
            int next_time = times[permutation[i]];
            double dist = distance(location, next_loc);
            time += dist / v;
            if (time > (double) next_time) {
                worked = false;
                break;
            }
            v *= m;
            location = next_loc;
        }
        if (worked) {
            return true;
        }
    } while (next_permutation(permutation, permutation + n));
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) { 
        int x, y, s;
        scanf(" %d %d %d", &x, &y, &s);
        locs[i] = make_pair(x, y);
        times[i] = s;
    }
    scanf(" %lf", &m);
    double lo = 0.0;
    double hi = 1.0;
    while (!works(hi)) {
        hi *= 2;
    }
    
    for (int i = 0; i < 100; i++) {
        double mid = lo + (hi - lo) / 2;
        if (works(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%lf\n", hi);
}
