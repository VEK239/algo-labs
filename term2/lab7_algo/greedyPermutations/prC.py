def generate(index, n):
    if index == 0:
        return n * lst[0]
    cur_price = lst[index]
    if (pow(10, index) > n):
        return min(cur_price, generate(index - 1, n))
    else:
        count = n // pow(10, index)
        return min(cur_price * count + min(cur_price, generate(index - 1, n % pow(10, index))), generate(index - 1, n))

with open("printing.in") as inf:
    n = int(inf.readline())
    lst = []
    for i in range(7):
        lst.append(int(inf.readline()))

with open("printing.out", "w") as ouf:
    ouf.write(str(generate(6, n)))