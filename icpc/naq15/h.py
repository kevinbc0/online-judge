import math

nn = int(input().strip())
for _ in range(nn):
    msg = input().strip()
    thing = []
    n = int(math.ceil(math.sqrt(len(msg))))
    count = 0
    for i in range(n):
        thing.append([])
        for _ in range(n):
            if count < len(msg):
                thing[i].append(msg[count])
                count += 1
            else:
                thing[i].append('*')
    ans = ''
    for i in range(n):
        for j in reversed(range(n)):
            if thing[j][i] != '*':
                ans += thing[j][i]
    print(ans)
