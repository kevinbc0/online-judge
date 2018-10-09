n = int(input())
moves = input()
cur = 0
to_print = 0
last = 0
for move in moves:
    cur += 1
    if move == 'R':
        for i in reversed(range(last, to_print + 1)):
            print(i + 1)
        to_print = cur
        last = cur
    else:
        to_print += 1
for i in reversed(range(last, n)):
    print(i + 1)
