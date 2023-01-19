a = int(input())
p = 81 * (10 ** 18)
L = ((a - p) % a + a) % a
if L == 0:
    L += a
R = 10 ** 18 - 1 + L
print(L, R)
