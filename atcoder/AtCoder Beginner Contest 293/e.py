a, p, m = map(int, input().split())
print((pow(a, p, m) + m - 1) % m * pow(a - 1, -1, m) % m)
