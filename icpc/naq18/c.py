from collections import defaultdict
config = list(map(int, input().split(' ')))
diffs = defaultdict(list)
for _ in range(config[0]):
    line = list(map(int, input().split(' ')))
    diffs[(False, False)].append(line)
    #[(line[0], line[1])] = line[2:]
for _ in range(config[1]):
    line = list(map(int, input().split(' ')))
    diffs[(False, True)].append(line)
    #[(line[0], line[1])] = line[2:]
for _ in range(config[2]):
    line = list(map(int, input().split(' ')))
    diffs[(True, False)].append(line)
    #[(line[0], line[1])] = line[2:]
for _ in range(config[3]):
    line = list(map(int, input().split(' ')))
    diffs[(True, True)].append(line)
    #[(line[0], line[1])] = line[2:]

keys = list(map(int, input().split(' ')))

def isblack(num):
    if (num - 4) % 12 in [1,3,6,8,10]:
        return True
    return False

dp = [[10000000000000] * config[4] for _ in range( 5)]
for li in dp:
    li[0] = 0
last_key = keys[0]
last_color = isblack(last_key)
for i in range(1, config[4]):
    key = keys[i]
    color = isblack(key)
    if key > last_key:
        for line in diffs[(last_color, color)]:
            dp[line[1] - 1][i] = min(dp[line[1] - 1][i], dp[line[0] - 1][i - 1] + line[key - last_key + 1])
    elif last_key > key:
        for line in diffs[(color, last_color)]:
            dp[line[0] - 1][i] = min(dp[line[0] - 1][i], dp[line[1] - 1][i - 1] + line[last_key - key + 1])
    else:
        for li in dp:
            li[i] = li[i - 1]
    last_key = key
    last_color = color
print(min([dp[i][config[4] - 1] for i in range(5)]))
