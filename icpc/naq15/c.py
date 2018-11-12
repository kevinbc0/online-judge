from collections import defaultdict

visited = set()
stack = []
count = 0

def dfs(name, graph):
    global stack, visited
    if name in visited:
        return
    visited.add(name)
    for node in graph[name]:
        dfs(node, graph)
    stack.append(name)

def count_dfs(name, t_graph):
    global visited, count
    if name in visited:
        return
    visited.add(name)
    count += 1
    for node in t_graph[name]:
        count_dfs(node, t_graph)

def solve():
    global stack, visited, count
    n = int(input())
    graph = defaultdict(list)
    t_graph = defaultdict(list)
    languages = defaultdict(list)
    names = []
    for _ in range(n):
        l = input().split()
        name = l[0]
        language = l[1]
        languages[language].append(name)
        names.append((name, language))
        for lang in l[2:]:
            languages[lang].append(name)
    for name, language in names:
        for person in languages[language]:
            if person == name:
                continue
            graph[name].append(person)
            t_graph[person].append(name)

    for name, _ in names:
        dfs(name, graph)

    visited = set()
    max_count = 0
    while len(stack) > 0:
        name = stack.pop()
        count_dfs(name, t_graph)
        max_count = max(max_count, count)
        count = 0
    print(n - max_count)
    

solve()
