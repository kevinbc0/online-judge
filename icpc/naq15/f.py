n = int(input())
for _ in range(n):
    line = input().lower()
    letters = set()
    for ch in line:
        if ord(ch) >= ord('a') and ord(ch) <= ord('z'):
            letters.add(ch)
    ans = ''
    for i in range(ord('a'), ord('z') + 1):
        if chr(i) not in letters:
            ans = ans + chr(i)
    if len(ans) == 0:
        print('pangram')
    else:
        print('missing {}'.format(ans))
