def fact(high, low):
    res = 1
    for i in range(low, high + 1):
        res *= i
    return res

def choose(n, k):
    if k > n / 2:
        k = n - k
    return fact(n, n - k + 1) / fact(k, 1)

def solve():
    t = int(input())
    for _ in range(t):
        r, s, x, y, w = map(int, input().strip().split())
        prob = 0
        for i in range(x, y + 1):
            prob += pow(s - r + 1, i) * pow(r - 1, y - i) * choose(y, i)
        if w * prob > pow(s, y):
            print('yes')
        else:
            print('no')


solve()
