from math import exp

def cosh(x):
    return (exp(x) + exp(-x)) / 2

def sinh(x):
    return (exp(x) - exp(-x)) / 2

def sag(a, d):
    return a * cosh(d / (2 * a)) - a

def solve():
    d, s = map(int, input().split())
    # find hi and lo
    hi = lo = 1
    while sag(lo, d) < s:
        lo /= 2
    while sag(hi, d) >= s:
        hi <<= 1

    # binary search
    for _ in range(250):
        mid = lo + (hi - lo) / 2
        if sag(mid, d) >= s:
            lo = mid
        else:
            hi = mid
    print(2 * lo * sinh(d / (2 * lo)))

solve()
