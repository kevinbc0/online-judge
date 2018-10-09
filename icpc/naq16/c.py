from collections import defaultdict
from heapq import heappush, heappop

def shortest_path(graph, item_counts, n):
    heap = [(0, -item_counts[1], 1)]
    visited = set()
    while len(heap) > 0:
        cost, count, node = heappop(heap)
        if node == n:
            print(cost, -count)
            return
        if node in visited:
            continue
        visited.add(node)
        for next_cost, next_node in graph[node]:
            heappush(heap, (cost + next_cost, count - item_counts[next_node], next_node))
    print('impossible')

def solve():
    n = int(input())
    item_counts = list(map(int, input().split()))
    item_counts = {i + 1: item_counts[i] for i in range(n)}
    m = int(input())
    graph = defaultdict(list)
    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((d, b))
        graph[b].append((d, a))
    shortest_path(graph, item_counts, n)

solve()
