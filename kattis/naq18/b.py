n = list(map(int, input().split(' ')))
a = max(n[0], n[1])
b = min(n[0], n[1])
x = 1
yy = 1
y = 0
xx = 0
while b != 0:
    q = a // b
    b, a = a%b, b
    xx, x = x - q * xx, xx
    yy, y = y - q * yy, yy
if (n[0] * n[1]) / a <= n[2]:
    print('yes')
else:
    print('no')
