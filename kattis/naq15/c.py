from collections import defaultdict
lang_outs = defaultdict(set)
person_lang = {}
graph = defaultdict(set)
numname = []
namenum = {}
n = int(input().strip())
for _ in range(n):
    lang = input().strip().split(' ')
    person_lang[lang[0]] = lang[1]
    for i in range(len(lang) - 2):
        lang_outs[lang[i + 2]].add(lang[0])
    lang_outs[lang[1]].add(lang[0])
for key,val in person_lang.items():
    graph[key].update(lang_outs[val])
    numname.append(key)
    namenum[key] = len(numname) - 1
val = [0] * n
comp = [-1] * n
time = 0
ncomps = 0
z = []
cont = []
print(graph)
def dfs(j, g):
    global time, ncomps, z, cont, val, comp
    time += 1
    low = time
    val[j] = time
    z.append(j)
    for e in graph[numname[j]]:
        e = namenum[e]
        if comp[e] < 0:
            if val[e] == 0:
                low = min(low, dfs(e, g))
    if low == val[j]:
        x = z.pop()
        comp[x] = ncomps
        cont.append(x)
        while(x != j):
            x = z.pop()
            comp[x] = ncomps
            cont.append(x)
        cont = []
        ncomps += 1
    val[j] = low
    return low



for i in range(n):
    if comp[i] < 0:
        dfs(i, graph);
print(val)
print(comp)
print(ncomps)

