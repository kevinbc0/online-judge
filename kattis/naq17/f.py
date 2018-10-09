def simulate(steps):
    x = 0
    y = 0
    dx = 0
    dy = 1
    for step in steps:
        if step == 'Forward':
            x += dx
            y += dy
        elif step == 'Right':
            dx, dy = (dy, -dx)
        else:
            dx, dy = (-dy, dx)
    return (x, y)


def solve():
    x, y = map(int, input().split())
    n = int(input())
    steps = []
    for _ in range(n):
        steps.append(input())
    for i in range(len(steps)):
        for inst in ['Left', 'Forward', 'Right']:
            if steps[i] == inst:
                continue
            copy = list(steps)
            copy[i] = inst
            if simulate(copy) == (x, y):
                print(i + 1, inst)
                return

solve()
