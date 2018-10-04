def solve():
    n, m = map(int, input().split())
    ans = ''
    for i in range(n):
        ans += str(i % 2)
    print(ans)

solve()
