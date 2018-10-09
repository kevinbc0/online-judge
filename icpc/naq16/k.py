def solve():
    n = int(input())
    for _ in range(n):
        l1, a1, l2, a2, lt, at = map(int, input().split())
        # iterate over all possibly values of x and y
        count = 0
        solx, soly = (0, 0)
        for x in range(1, lt // l1 + 1):
            y = (lt - l1 * x) // l2
            if y * l2 + x * l1 != lt:
                continue
            if a1 * x + a2 * y == at:
                if x == 0 or y == 0:
                    continue
                count += 1
                solx, soly = (x, y)
        if count == 1:
            print(solx, soly)
        else:
            print('?')

solve()
