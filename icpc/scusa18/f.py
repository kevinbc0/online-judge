from collections import defaultdict
def solve():
	n = int(input())
	for _ in range(n):
		k = int(input())
		counts = defaultdict(int)
		for _ in range(k):
			name, count = input().split()
			count = int(count)
			counts[name] += count
		counts = [(-v, k) for k, v in counts.items()]
		counts.sort()
		print(len(counts))
		for count, item in counts:
			print(item, -count)

solve()
