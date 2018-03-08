def solve():
    n = int(input())
    counts = list(map(int, input().split()))
    s = 2 ** (n - 1)
    e = n - 2
    lng = (2 ** (-3 / 4))
    short = 2 * (2 ** (-5 / 4))
    tape = -2 * (lng + short)
    cur_size = 2 ** e

    for count in counts:
        if ((n - 1) - e) % 2 == 0:
            lng /= 2
        else:
            short /= 2

        amount = 0
        if count * cur_size < s:
            amount = count
        else:
            amount = (s / cur_size)

        s -= amount * cur_size
        tape += amount * (2 * (lng + short))

        if s == 0:
            print(tape / 2)
            return

        e -= 1
        cur_size >>= 1

    print('impossible')

solve()
