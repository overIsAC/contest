for T in range(int(input())):
    n = int(input())
    s = input()
    a = int(s)
    if s[0] != '9':
        print(10**len(s) - 1 - a)
    else:
        print(int('1'*(len(s)+1))-a)
