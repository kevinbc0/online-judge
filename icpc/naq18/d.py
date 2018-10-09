lw = list(map(int, input().split(' ')))
cars = []
for _ in range(lw[0]):
    cars.insert(0, list(map(int, input().split(' '))))
count = 0
for i in reversed(range(lw[0])):
    if count % 2 == 1:
        cars[i][2] *= -1
    count += 1
frog = input().split(' ')
frogpos = [int(frog[0]), 0]
dead = False
for move in frog[1]:
    if move == 'U' and frogpos[1] < lw[0] + 1:
        frogpos[1] += 1
    elif move == 'R' and frogpos[0] < lw[1] - 1:
        frogpos[0] += 1
    elif move == 'L' and frogpos[0] > 0:
        frogpos[0] -= 1
    elif move == 'D' and frogpos[1] > 0:
        frogpos[1] -= 1
    if not(frogpos[1] < 1 or frogpos[1] > lw[0]):
        car = cars[frogpos[1] - 1]
        relpos = (frogpos[0] - car[0]) % car[1]
        if relpos <= car[2] and not(relpos == 0 and abs(car[2]) < car[1]):
            dead = True
            break
    for i in range(lw[0]):
        cars[i][0] = (cars[i][0] + cars[i][2]) % cars[i][1]
if dead or frogpos[1] <= lw[0]:
    print('squish')
else:
    print('safe')
