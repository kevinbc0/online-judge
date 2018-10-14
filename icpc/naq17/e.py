from collections import defaultdict
from functools import lru_cache
import sys

children = defaultdict(list)
speeds = {}

@lru_cache(maxsize=1000)
def compute_dp(name):
    global children
    child_scores = []
    for child in children[name]:
        child_scores.append((child, compute_dp(child)))
    total_score = (0, 0)
    for _, score in child_scores:
        total_score = (total_score[0] + score[0], total_score[1] + score[1])
    best_score = total_score
    for child, score in child_scores:
        new_score = (total_score[0] - score[0], total_score[1] - score[1])
        for cchild in children[child]:
            cchild_score = compute_dp(cchild)
            new_score = (new_score[0] + cchild_score[0], new_score[1] + cchild_score[1])
        new_score = (new_score[0] + 1, new_score[1] + min(speeds[name], speeds[child]))
        if new_score[0] > best_score[0] or (new_score[0] == best_score[0] and new_score[1] > best_score[1]):
            best_score = new_score
    return best_score


def solve():
    sys.setrecursionlimit(5000)
    global children, speeds
    n = int(input())
    ceo = ''
    for _ in range(n):
        name, speed, parent = input().split()
        speed = float(speed)
        speeds[name] = speed
        children[parent].append(name)
        if parent == 'CEO':
            ceo = name
    teams, total_speed = compute_dp(ceo)
    print(teams, total_speed / teams)

solve()
