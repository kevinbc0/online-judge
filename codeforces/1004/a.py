def solve():
    n, d = map(int, input().strip().split())
    hotels = list(map(int, input().strip().split()))
    ans = 0
    for i in range(n - 1):
        if hotels[i + 1] - hotels[i] > 2 * d:
            ans += 2
        elif hotels[i + 1] - hotels[i] == 2 * d:
            ans += 1
    print(ans + 2)
        

solve()
