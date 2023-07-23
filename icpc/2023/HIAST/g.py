def f(n):
    ans = 0
    while n > 0:
        ans += 1
        n //= 2
    return ans-1


for i in range(int(input())):
    n = int(input())
    print(2**f(n) - 1)
