def doubleq(a, b):
	EPS = 5
	return abs(a -b) < EPS

def to_frequency(a):
	frequencies = [440, 466.16, 493.88, 523.25, 554.37, 587.33, 622.25, 659.26, 698.46, 739.99, 783.99, 830.61]
	for i in range(12):
		if doubleq(a, frequencies[i]):
			return i
	print('asdfsadfd', a)
	return

def matches(d1, d2):
	for key in d1:
		if key not in d2:
			return False
	return True

def solve():
	n = int(input())
	pitches = []
	pitchset = set()
	for i in range(n):
		frequency = float(input())
		while frequency >= 879:
			frequency /= 2
		while frequency <= 439:
			frequency *= 2
		pitch = to_frequency(frequency)
		pitches.append(pitch)
		pitchset.add(pitch)

	g = {10: 'G', 0: 'A', 2: 'B', 3: 'C', 5: 'D', 7: 'E', 9: 'F#'}
	c = {3: 'C', 5: 'D', 7: 'E', 8: 'F', 10: 'G', 0: 'A', 2: 'B'}
	eb = {6: 'Eb', 8: 'F', 10: 'G', 11: 'Ab', 1: 'Bb', 3: 'C', 5: 'D'}
	fs = {9: 'F#', 11: 'G#', 0: 'A', 2: 'B', 4: 'C#', 5: 'D', 7: 'E'}
	gm = {10: 'G', 0: 'A', 1: 'Bb', 3: 'C', 5: 'D', 6: 'Eb', 8: 'F'}
	keys = {'G major': g, 'C major': c, 'Eb major': eb, 'F# minor': fs, 'G minor': gm}

	match = ''
	for key, keyset in keys.items():
		if matches(pitchset, keyset):
			if match != '':
				print('cannot determine key')
				return
			match = key
	if match == '':
		print('cannot determine key')
		return
	
	keyset = keys[match]
	print(match)
	for pitch in pitches:
		print(keyset[pitch])	


solve()
