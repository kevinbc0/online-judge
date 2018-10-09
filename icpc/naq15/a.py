def to_list(num):
    l = list(num)
    ret = list(map(lambda x: int(x) if ord(x) >= ord('0') and ord(x) <= ord('9')  else ord(x) - ord('a') + 10, l))
    return ret

def base10(l, base):
    l = list(reversed(l))
    res = 0
    for i in range(len(l)):
        if base == 1 and l[i] != 1:
            return False
        if base != 1 and l[i] >= base:
            return False
        res += pow(base, i) * l[i]
    return res

def solve():
    t = int(input())
    for _ in range(t):
        ans = ''
        n1, op, n2, _, n3 = input().split()
        new1, new2, new3 = [to_list(n1), to_list(n2), to_list(n3)]
        for i in range(1, 37):
            n1, n2, n3 = (base10(new1, i), base10(new2, i), base10(new3, i))
            if not n1 or not n2 or not n3:
                continue
            i = i if i <= 9 else chr(ord('a') + (i - 10)) if i < 36 else 0
            if op == '+' and n1 + n2 == n3:
                ans += str(i)
            elif op == '-' and n1 - n2 == n3:
                ans += str(i)
            elif op == '*' and n1 * n2 == n3:
                ans += str(i)
            elif op == '/' and n1 / n2 == n3:
                ans += str(i)
        if len(ans) == 0:
            ans += "invalid"
        print(ans)

solve()
