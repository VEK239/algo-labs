with open("vectors2.in") as inf:
    n = int(inf.readline())
lst = [[] for i in range(n)]
lst[0] = ['0' * n]
count = 0

for i in range(1, (n + 2) // 2 + 1):
    for el in lst[i - 1]:
        if el[n - 1] == '0' and el[n - 2] == '0':
            lst[i].append(el[:n - 1] + '1')
        for k in range(n - 2, 0, -1):
            if el[k - 1] == '0' and el[k + 1] == '0':
                lst[i].append(el[:k] + '1' + el[k + 1:])
            else:
                break
        if el[0] == '0' and el[1] == '0':
            lst[i].append('1' + el[1:])

res = set()
for i in range(n):
    for j in range(len(lst[i])):
        res.add(lst[i][j])
res = list(res)
res.sort()

printing = str(len(res)) + '\n'
for el in res:
    printing += el + '\n'

with open("vectors2.out", "w") as ouf:
    ouf.write(printing)

