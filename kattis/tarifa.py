from functools import reduce

x = int(input())
n = int(input())
print(x + reduce(lambda x, y: x + y, [x - num for num in [int(input()) for _ in range(n)]]))
