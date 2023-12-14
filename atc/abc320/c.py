n = int(input())
u = input()
v = input()
w = input()

ans = 10 ** 20
for i in range(3 * n):
    for j in range(3 * n):
        for k in range(3 * n):
            if u[i % n] == v[j % n] == w[k % n] and i != j and i != k and j != k:
                ans = min(max(i, j, k), ans)
if ans == 10 ** 20:
    ans = -1
print(ans)
