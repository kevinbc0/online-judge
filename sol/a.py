n = int(input())
for _ in range(n):
	x, y = map(int, input().split())
	unit = 1
	for i in range(63):
		if(max(x, y) < unit):
			break;
		unit *= 2
	total = 0
	while unit > 2:
		unit //= 2
		if x < unit and y >= unit:
			if not (x == unit - 1 and y == unit):
				total += 1
			x, y = unit * 2 - y - 1, x
		if y < unit and x >= unit:
			if not (x == unit and y == unit - 1):
				total += 3
			x, y = y, unit * 2 - x - 1
		if y >= unit and x >= unit:
			y -= unit
			x -= unit
	print(total % 4)
