import math

def count(lst):
    res = 0
    for i in range(1, len(lst)):
        res += lst[i - 1] * lst[i]
    return res % r

def generate(lst, k = 0):
    if k == len(lst):
        permutations.append(count(lst))
    for i in range(k, len(lst)):
        lst[k], lst[i] = lst[i], lst[k]
        generate(lst, k + 1)
        lst[k], lst[i] = lst[i], lst[k]

def isCorrect(k):
    count = 2
    for i in range(2, int(math.sqrt(k)) + 1):
        if k % i == 0:
            count += 2
        if i * i == k:
            count -= 1
    return (k == 0 or count % 3 == 0) and k != 1

with open("beautiful.in") as inf:
    n, r = map(int, inf.readline().split())
permutations = []
generate([i for i in range(1, n + 1)])
# print(len(permutations))
correct = [isCorrect(i) for i in range(r + 1)]
count = 0
for el in permutations:
    if correct[el]:
        count += 1

with open("beautiful.out", "w") as ouf:
    ouf.write(str(count))
