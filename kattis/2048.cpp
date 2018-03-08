#include <cstdio>
#include <iostream>
#include <iterator>

using namespace std;

int grid[4][4];

inline void rotate(int r) {
    int grid_copy[4][4];
    copy(&grid[0][0], &grid[0][0] + 16, &grid_copy[0][0]);
    
    for (int _ = 0; _ < r; _++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                grid[j][3 - i] = grid_copy[i][j];
            }
        }
        copy(&grid[0][0], &grid[0][0] + 16, &grid_copy[0][0]);
    }
}

// Shift to the left.
inline void shift_grid() {
    for (int i = 0; i < 4; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                count++;
            } else if (count > 0) {
                grid[i][j - count] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    }
}

inline void combine() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == grid[i][j + 1]) {
                grid[i][j] *= 2;
                grid[i][j + 1] = 0;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    int dir;
    cin >> dir;
    rotate(4 - dir);
    shift_grid();
    combine();
    shift_grid();
    rotate(dir);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
