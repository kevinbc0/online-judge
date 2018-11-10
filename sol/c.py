def to_int(c):
	return ord(c) - ord('a')

def solve():
	n = int(raw_input())
	for _ in range(n):
		a = raw_input()
		b = raw_input()
		s = set()
		for i in xrange(len(b)):
			counts = [0 for _ in range(26)]
			for j in xrange(i + 1, len(b) + 1):
				char = b[j - 1]
				counts[to_int(char)] += 1
				s.add(tuple(counts))
		bestlen = 0
		beststart = 0
		bestend = 0
		for i in xrange(len(a)):
			counts = [0 for _ in range(26)]
			for j in xrange(i + 1, len(a) + 1):
				char = a[j - 1]
				counts[to_int(char)] += 1
				if tuple(counts) in s:
					if j - i > bestlen:
						bestlen = j - i
						beststart = i
						bestend = j
				
		if bestlen == 0:
			print 'NONE'
		else:
			print a[beststart:bestend]

solve()
