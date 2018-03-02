import sys

v = {}

def interpret_command(line):
    c = line.split()
    if c[0] == 'define':
        v[c[2]] = int(c[1])
    else:
        if c[1] not in v or c[3] not in v:
            print('undefined')
            return

        a = v[c[1]]
        b = v[c[3]]
        print('true' if (a == b and c[2] == '=') or (a < b and c[2] == '<') or (a > b and c[2] == '>') else 'false')

def main():
    for line in sys.stdin:
        interpret_command(line)

main()
