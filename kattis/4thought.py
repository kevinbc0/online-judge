import itertools

lookup = {}

def generate_lookup():
    for ops in itertools.product(['+', '-', '*', '//'], repeat=3):
        exp = '4' + '4'.join(ops) + '4'
        val = eval(exp)
        lookup[val] = ops

def main():
    generate_lookup()
    t = int(input())
    for _ in range(t):
        n = int(input())
        if n not in lookup:
            print('no solution')
        else:
            print('4 ' + ' 4 '.join(lookup[n]).replace('//', '/') + ' 4 =', n)
    
main()
