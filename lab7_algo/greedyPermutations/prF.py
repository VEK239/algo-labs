def compZero(obj):
    return obj[0]
def compOne(obj):
    return obj[1]

def msort(lst):
    if len(lst) == 1:
        return lst;
    middle = len(lst) // 2
    left = lst[:middle]
    right = lst[middle:]
    return mergesort(msort(left), msort(right))

def mergesort(left, right):
    i = 0
    j = 0
    result = []
    global inversion
    invers = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
            invers += len(left) - i
    if i < len(left):
        for k in range(i, len(left)):
            result.append(left[k])
    else:
        for k in range(j, len(right)):
            result.append(right[k])
    inversion += invers
    return result

with open("john.in") as inf:
    n = int(inf.readline())
    lst = []
    for i in range(n):
        ls = list(map(int,inf.readline().split()))
        lst.append(ls)

lst.sort(key=compOne)
lst.sort(key=compZero)
inversion = 0
invCountingList = msort([el[1] for el in lst])


with open("john.out", "w") as ouf:
    ouf.write(str(inversion))
