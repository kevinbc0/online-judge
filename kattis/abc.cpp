#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    int a = min(x, min(y, z));
    int c = max(x, max(y, z));
    int b = (x + y + z) - a - c;

    char str[4];
    scanf("%s", str);
    for (int i = 0; i < 3; i++) {
        char ch = str[i];
        printf("%d ", ch == 'A' ? a : (ch == 'B' ? b : c));
    }
    printf("\n");
}
