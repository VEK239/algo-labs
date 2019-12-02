requests = []
with open("request.in") as inf:
    n = int(inf.readline())
    for i in range(n):
        a, b = inf.readline().split()
        requests.append([int(b), int(a)])
# print(requests)
requests.sort()
count = 1
endingTime = requests[0][0]
for i in range(1, len(requests)):
    if requests[i][1] >= endingTime:
        count += 1
        endingTime = requests[i][0]
with open("request.out", "w") as ouf:
    ouf.write(str(count))