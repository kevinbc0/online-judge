things = list(map(int, input().strip().split(' ')[1:]))
things.sort()
last = len(things) - 1
ans = 0
while last > 2:
    one = things[0] + things[1] * 2 + things[last]
    if things[last] + things[last - 1] + things[0] * 2 < one:
        ans += things[0] + things[last]
        last -= 1
    else:
        ans += one
        last -= 2
if last == 2:
    ans += things[0] + things[1] + things[2]
elif last == 1:
    ans += things[1]
else:
    ans += things[0]
print(ans)
