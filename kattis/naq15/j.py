n = int(input())

g = {}

for i in range(n):
    line = input().split(" ")
    start = line[0]
    neighbors = line[1:]
    if start not in g:
        g[start]=[]
    g[start].extend(neighbors)
    for neighbor in neighbors:
        if neighbor not in g:
            g[neighbor] = []
        g[neighbor].append(start)


line = input().split(" ")
start = line[0]
end = line[1]

fromv = {}
tovisit = []

if start not in g or end not in g:
    print("no route found")
else:
    tovisit.insert(0, start)
    fromv[start]=None
    while(len(tovisit)>0):
        cur = tovisit.pop()
        if cur == end:
            path = []
            while cur is not None:
                path.insert(0, cur)
                cur = fromv[cur]
            print(" ".join(path))

            quit()
        
        if cur in g:
            for neighbor in g[cur]:
                if neighbor not in fromv:
                    fromv[neighbor] = cur
                    tovisit.insert(0, neighbor)

                    
    print("no route found")

