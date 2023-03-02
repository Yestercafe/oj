import random

N = 100000
print(N)
for _ in range(N):
	s = ""
	len = random.randint(3, 50)
	for _ in range(len):
		s += (chr(ord('a') + random.randint(0, 25)))
	print(s)