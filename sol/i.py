n = int(raw_input())

dice = {}


def twist(t, bo, f, ba, l, r):
	f, r, ba, l = r, ba, l, f
	return t, bo, f, ba, l, r

def turn(t, bo, f, ba, l, r):
	t, bo, l, r = r, l, t, bo 
	return t, bo, f, ba, l, r

def flip(t, bo, f, ba, l, r):
	t, bo,  l, r = bo, t,  r, l
	return t, bo, f, ba, l, r

max_c = [0]


def add_d(d):
	count=1
	if d in dice:
		count += dice[d]
		dice[d]+=1
	else:
		dice[d] = 1
	max_c[0]=max(max_c[0], count)


def add_df(d):
	t, bo, f, ba, l, r = d

	if d in dice:
		add_d(d)
		return	
	nd = d
	for _ in range(4):
		nd = tuple(twist(*nd))
		if nd in dice:
			add_d(nd)
			return
	nd = tuple(flip(*d))
	for _ in range(4):
		nd = tuple(twist(*nd))
			
		if nd in dice:
			add_d(nd)
			return
	nd = tuple(turn(*d))
	for _ in range(4):
		nd = tuple(twist(*nd))
		if nd in dice:
			add_d(nd)
			return
	nd = tuple(flip(*nd))
	for _ in range(4):
		nd = tuple(twist(*nd))
		if nd in dice:
			add_d(nd)
			return
	nd = tuple(twist(*d))
	nd = tuple(turn(*nd))
	for _ in range(4):
		nd = tuple(twist(*nd))
		if nd in dice:
			add_d(nd)
			return
	nd = tuple(flip(*nd))
	for _ in range(4):
		nd = tuple(twist(*nd))
		if nd in dice:
			add_d(nd)
			return

	add_d(d)


for _ in range(n):
	d = tuple([int(p) for p in raw_input().split(" ")])
	add_df(d)




print(max_c[0])
