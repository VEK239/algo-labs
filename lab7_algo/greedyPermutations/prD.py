with open("sequence.in") as inf:
    n = int(inf.readline())
    sequence = list(map(int, inf.readline().split()))
sum = 0
for i in range(len(sequence)):
    sequence[i] = [sequence[i], i + 1]
    sum += sequence[i][0]
sum = sum / 2
sequence.sort(reverse=True)
# print(sequence)
res = ''
count = 0
for el in sequence:
    if el[0] <= sum and n > 0:
        res += str(el[1]) + ' '
        count += 1
        sum -= el[0]
with open("sequence.out", "w") as ouf:
    if sum == 0:
        ouf.write(str(count) + '\n' + res)
    else:
        ouf.write("-1")