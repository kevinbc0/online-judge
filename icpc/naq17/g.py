def solve():
    n = int(input())
    points = set()
    dxs = [-2018, 0, 2018, 0, 1680, 1118, 1680, 1118, -1680, -1118, -1680, -1118]
    dys = [0, -2018, 0, 2018, 1118, 1680, -1118, -1680, 1118, 1680, -1118, -1680]
    count = 0
    for _ in range(n):
        x, y = map(int, input().split())
        for dx, dy in zip(dxs, dys):
            if (x + dx, y + dy) in points:
                count += 1
            points.add((x, y))
    print(count)
            

solve()
