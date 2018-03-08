from math import *

h, d = map(int, input().split())
print(ceil(h / sin(radians(d))))
