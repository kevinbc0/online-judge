def solve():
	n, q = map(int, input().split())
	companies = dict()
	locations = list(map(int, input().split()))
	for i in range(len(locations)):
		companies[i + 1] = locations[i]

	for _ in range(q):
		op, a, b = map(int, input().split())
		if op == 1:
			companies[a] = b
		if op == 2:
			print(abs(companies[a] - companies[b]))

solve()
