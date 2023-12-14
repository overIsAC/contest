s = input()


def f(s):
    return s == s[::-1]

ans=1
for i in range(len(s)):
    for j in range(i, len(s)):
        if f(s[i:j+1]):
            ans=max(ans, j-i+1)
print(ans)