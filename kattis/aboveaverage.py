def solve():
    l = list(map(int, input().split()))
    l.pop(0)
    average = sum(l) / len(l)
    print("%.3f%%" % (100 * len(list(filter(lambda x: x > average, l))) / len(l)))

def main():
    c = int(input())
    for _ in range(c):
        solve()

main()
