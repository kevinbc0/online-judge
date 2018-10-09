from itertools import combinations
n = int(input())

all_rows = set()

row_sets = [[] for _ in range(n)]

for i in range(n):
    for r in range(5):
        row = sorted([int(inp) for inp in input().split(" ")])
        tup = (row[0], row[1], row[2], row[3], row[4])
        all_rows.add(tup)
        row_sets[i].append(set(row))
    if i!=n-1:
        input()


for bi in range(n - 1):
    for bj in range(bi +1, n):
        for ri in row_sets[bi]:
            for rj in row_sets[bj]:
                if len(ri & rj) > 0:
                    inter = ri & rj
                    for num in inter:
                        seq = (ri | rj)
                        seq.remove(num)
                        combos = combinations(sorted(list(seq)), 5)
                        all_work = True
                        for combo in combos:
                            scombo = set(combo)
                            if len(scombo & ri) < 5 and len(scombo & rj) < 5:
                                if combo in all_rows:
                                    all_work = False
                                    break
                        if all_work:
                            print("%d %d" % (bi+1, bj+1))
                            quit()
print("no ties")
