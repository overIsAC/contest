for ___ in range(int(input())):
    s = input()
    a = []
    t = ""
    for i in s:
        if t != "" and i.isalpha() != t[-1].isalpha():
            a.append(t)
            t = ""
        t += i
    a.append(t)
    for i in range(0, len(a), 2):
        for j in range(int(a[i])):
            print(a[i + 1], end="")
    print()
