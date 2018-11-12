n = int(input())
for _ in range(n):
	m = int(input())
	k = 1
	for i in range(1, m + 1):
		k *= i
		k %= 10
	print(k)
