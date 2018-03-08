def solve(n):
    days = 1
    statues = 1
    while n > statues:
        statues <<= 1
        days += 1

    return days

n = int(input())
print(solve(n))
