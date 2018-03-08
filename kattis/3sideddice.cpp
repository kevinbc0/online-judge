#include <cstdio>
#include <iostream>
#include <iterator>

using namespace std;
using ll = long long;

double mat[3][3];
double target[3];
ll sol[3];

double det(double m[3][3]) {
    double d = 0;
    for (int i = 0; i < 3; i++) {
        d += (m[i][0] * m[(i + 1) % 3][1] * m[(i + 2) % 3][2]);
        d -= (m[i][0] * m[(i + 2) % 3][1] * m[(i + 1) % 3][2]);
    }

    return d;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n = 0;
    while (n < 3) {
        n++;
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                cin >> mat[i][j];
                mat[i][j] /= (double) 10000;
            }
            if (mat[0][0] + mat[1][0] + mat[2][0] == 0) {
                return 0;
            }
        }

        double determinant = det(mat);
        if (determinant == 0) {
            printf("YES\n");
            continue;
        }

        for (int i = 0; i < 3; i++) {
            cin >> target[i];
            target[i] /= (double) 10000;
        }

        double mat_copy[3][3];
        for (int i = 0; i < 3; i++) {
            copy(&mat[0][0], &mat[0][0] + 9, &mat_copy[0][0]);
            for (int j = 0; j < 3; j++) {
                mat_copy[j][i] = target[j];
            }

            /*
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%f ", mat_copy[i][j]);
                }
                printf("\n");
            }
            */

            sol[i] = (det(mat_copy) * 10000) / determinant;
        }

        if (sol[0] <= 0 || sol[1] <= 0 || sol[2] <= 0 || (sol[0] + sol[1] + sol[2] != 10000)) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
    }
}
