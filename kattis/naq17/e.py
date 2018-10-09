from collections import defaultdict


def solve():
    n = int(input())
    children = defaultdict(list)
    speeds = {}
    for _ in range(n):
        name, speed, parent = input().split()
        speed = float(speed)
        speeds[name] = speed
        children[parent].append(name)

solve()
