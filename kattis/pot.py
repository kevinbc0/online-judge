n = int(input())
sum = 0
for _ in range(n):
    num = input()
    sum += int(num[:-1]) ** int(num[-1])

print(sum)
