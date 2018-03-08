#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int MAXN = 1003;

int apt[MAXN][MAXN];
int r, c;

int largest_perimeter(int i) {
    vector<int> stack;
    int maxp = 0;
    for (int j = 0; j < c + 1; j++) {
        while (stack.size() != 0 && (j == c || apt[i][stack.back()] > apt[i][j])) {
            int index = stack.back();
            stack.pop_back();
            int last = stack.size() == 0 ? -1 : stack.back();
            int perimeter = apt[i][index] == 0 ? 0 : 2 * (apt[i][index] + (j - last - 1));
            maxp = max(maxp, perimeter);
        }

        stack.push_back(j);
    }

    return maxp;
}

void solve() {
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            apt[i][j] = apt[i][j] == 1 ? apt[i - 1][j] + 1 : 0; 
        }
    }

    int sol = 0;
    for (int i = 0; i < r; i++) {
        sol = max(largest_perimeter(i), sol);
    }

    printf("%d\n", sol - 1);
}

int main(int argc, char* argv[]) {
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; i++) {
        char str[c + 1];
        scanf("%s", str);

        for (int j = 0; j < c; j++) {
            apt[i][j] = str[j] == '.';
        }
    }
    
    solve();
}
