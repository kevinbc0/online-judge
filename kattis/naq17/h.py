from collections import deque

def distance(loc1, loc2):
    return pow(pow(loc1[0] - loc2[0], 2) + pow(loc1[1] - loc2[1], 2), 0.5)

def total_distance(locs):
    total = 0
    for i in range(len(locs) - 1):
        total += distance(locs[i], locs[i + 1])
    return total

def solve():
    n, t = map(int, input().split())
    locs = []
    q = deque()
    for _ in range(n):
        x, y, time = map(int, input().split())
        locs.append((x, y))
        q.append((x, y, time))
    
    gps_locs = []
    gps_locs.append((locs[0][0], locs[0][1]))
    cur_time = t
    while len(q) > 1:
        first = q[0]
        second = q[1]
        if cur_time > second[2]:
            q.popleft()
            continue
        frac = (cur_time - first[2]) / (second[2] - first[2])
        gpsx = first[0] + (second[0] - first[0]) * frac
        gpsy = first[1] + (second[1] - first[1]) * frac
        gps_locs.append((gpsx, gpsy))
        cur_time += t
    gps_locs.append((q[0][0], q[0][1]))
    actual = total_distance(locs)
    gps_dist = total_distance(gps_locs)
    print(100 * (actual - gps_dist) / actual)

solve()
