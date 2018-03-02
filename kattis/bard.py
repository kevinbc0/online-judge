def solve():
    n = int(input())
    e = int(input())

    songs = []

    for _ in range(e):
        a = input().split()
        x = int(a[0])
        y = a[1:]

        if '1' in y:
            new_song = set()
            for v in y:
                new_song.add(v)
            songs.append(new_song)
        else:
            v_set = set(y)
            for song in songs:
                if len(song.union(v_set)) > 0:
                    song.update(v_set)

    villagers = set(str(i + 1) for i in range(n))
    for song in songs:
        villagers = villagers.intersection(song)

    sol = []
    for villager in villagers:
        sol.append(int(villager))

    sol.sort()
    for s in sol:
        print(s)

solve()
