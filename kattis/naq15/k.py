from collections import defaultdict, deque

def distance(x1, y1, x2, y2):
    return pow(x2 - x1, 2) + pow(y2 - y1, 2)

def works(k, circles):
    circles = circles[:k + 1]
    
    # build graph
    graph = defaultdict(list)
    for i in range(1, len(circles)):
        x, y, r = circles[i]
        if x - r <= 0:
            graph[i].append(0)
            graph[0].append(i)
        if x + r >= 200:
            graph[i].append(1000)
            graph[1000].append(i)
        for j in range(i + 1, len(circles)):
            x2, y2, r2 = circles[j]
            if distance(x, y, x2, y2) <= pow(r + r2, 2):
                graph[i].append(j)
                graph[j].append(i)

    # bfs from 0 to find a path to 1000
    visited = set()
    visited.add(0)
    queue = deque()
    queue.append(0)
    while len(queue) > 0:
        circle = queue.popleft()
        for circle in graph[circle]:
            if circle == 1000:
                return False
            elif circle not in visited:
                visited.add(circle)
                queue.append(circle)
    return True
            

def solve():
    n = int(input())
    circles = [0]
    for _ in range(n):
        x, y, r = map(int, input().strip().split())
        circles.append((x, y, r))

    lo = 0
    hi = n
    while lo + 1 < hi:
        mid = (hi + lo) // 2
        if works(mid, circles):
            lo = mid
        else:
            hi = mid
    print(lo)

solve()
