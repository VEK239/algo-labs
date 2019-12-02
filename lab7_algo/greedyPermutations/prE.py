def compZero(obj):
    return obj[0]
def compOne(obj):
    return obj[1]
def compThree(obj):
    return obj[3]


with open("apples.in") as inf:
    n, height = map(int, inf.readline().split())
    applesPlus = []
    applesMinus = []
    for i in range(n):
        a, b = map(int, inf.readline().split())
        if b - a > 0:
            applesPlus.append([a, b, i + 1, b - a])
        else:
            applesMinus.append([a, b, i + 1, b - a])
applesPlus.sort(key=compOne, reverse=True)
applesPlus.sort(key=compZero)
applesMinus.sort(key=compOne, reverse=True)

ok = True
res = ''
for apple in applesPlus:
    height -= apple[0]
    if height <= 0:
        ok = False
        break
    else:
        height += apple[1]
        res += str(apple[2]) + ' '
for apple in applesMinus:
    height -= apple[0]
    if height <= 0:
        ok = False
        break
    else:
        height += apple[1]
        res += str(apple[2]) + ' '

with open("apples.out", "w") as ouf:
    if ok:
        ouf.write(res)
    else:
        ouf.write('-1')
