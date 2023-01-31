for i in range(int(input())):
    n = int(input())
    ok = False
    x = 0
    y = 0
    if n % 2 == 0:
        ok = True
        x = n // 2
        y = 1
    for i in range(1, 20):
        if ok:
            break
        for j in range(1, 30):
            v = i ** j * j + j ** i * i
            if v == n:
                ok = True
                x = i
                y = j
                break
            if v > n:
                break
    if ok:
        print(x, y)
    else:
        print(-1)
