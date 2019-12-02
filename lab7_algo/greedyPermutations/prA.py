with open("cobbler.in") as inf:
    w, n = map(int, inf.readline().split())
    lst = list(map(int, inf.readline().split()))
lst.sort()
count = 0
while w > 0 and len(lst) > 0:
    ls = lst.pop(0)
    if w - ls >= 0:
        w -= ls
        count += 1
    else:
        break
with open("cobbler.out", "w") as ouf:
    ouf.write(str(count))