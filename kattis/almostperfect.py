from math import sqrt
import sys

def solve(n):
    s = 0
    root = int(sqrt(n))
    for i in range(2, root + 1 if n % root == 0 else root):
        s = s + (i + int(n / i) if n % i == 0 else 0)
        if i == int(n / i):
            s -= i

    s += 1
    print(n, "perfect" if s == n else ("almost perfect" if s <= n + 2 and s >= n -2 else "not perfect"))

def main():
    for line in sys.stdin:
        solve(int(line))


main()
