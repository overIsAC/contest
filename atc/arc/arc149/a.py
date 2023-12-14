n, m = map(int, input().split())

p = 1
if m % 16 == 0:
    print(-1)
    exit(0)

if m % 25 == 0:
    print(-1)
    exit(0)

while m % 2 == 0:
    m /= 2
    p *= 2

if m % 5 == 0:
    if p > 1:
        print(-1)
        exit(0)
    else:
        p *= 5
        m /= 5

m *= p
v = 10 ** n - 1
v //= 9

while v:
    for i in range(9, 0, -1):
        if i % p == 0:
            vv = i * v
            if vv % m == 0:
                print(vv)
                exit(0)
            if vv < m:
                print(-1)
                exit(0)
    v //= 10

print(-1)