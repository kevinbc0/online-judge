""" This code was too slow, TLE """

weights = []
apsp = []
n = 0
q = 0
terminate = False

def read_graph():
    global n, m, q, weights, apsp, terminate
    n, m, q = map(int, input().strip().split())
    if n == 0 and m == 0 and q == 0:
        terminate = True
        return

    weights = [[float('inf') for _ in range(n)] for _ in range(n)]
    for i in range(n):
        weights[i][i] = 0
    
    for _ in range(m):
        u, v, w = map(int, input().strip().split())
        weights[u][v] = min(weights[u][v], w)

    apsp = list(weights)

def compute_apsp():
    global apsp
    for i in range(n):
        for j in range(n):
            for k in range(n):
                apsp[j][k] = min(apsp[j][k], apsp[j][i] + apsp[i][k])

    for i in range(n):
        for j in range(n):
            for k in range(n):
                apsp[j][k] = '-Infinity' if apsp[j][i] < float('inf') and apsp[i][k] < float('inf') and apsp[i][i] < 0 else apsp[j][k]

    for i in range(n):
        for j in range(n):
            apsp[i][j] = 'Impossible' if apsp[i][j] == float('inf') else apsp[i][j]

def run_queries():
    for _ in range(q):
        u, v = map(int, input().strip().split())
        print(apsp[u][v])

def main():
    while True:
        read_graph()
        if terminate:
            return
        compute_apsp()
        run_queries()
        print

main()
