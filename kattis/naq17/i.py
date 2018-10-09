def solve():
    n = int(input())
    for _ in range(n):
        gnomes = list(map(int, input().split()))
        for i in range(2, len(gnomes)):
            if gnomes[i] != gnomes[i - 1] + 1:
                print(i)
                break

solve()
