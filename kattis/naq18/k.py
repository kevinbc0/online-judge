def solve():
    decode, code = input().split()
    i = 0 
    if decode == 'E':
        out = ''
        while i < len(code):
            char = code[i]
            count = 1
            i += 1
            while i < len(code) and code[i] == char:
                count += 1
                i += 1
            out += char + str(count)
        print(out)
    elif decode == 'D':
        out = []
        while i < len(code):
            char = code[i]
            num = code[i + 1]
            out.extend([char for _ in range(int(num))])
            i += 2

        print(''.join(out))

solve()
