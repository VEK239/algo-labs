def comp(obj):
    return obj[0]

def treeBuild(my_map):
    size = len(my_map)
    lst = [[w, w, my_map[w][0], my_map[w][1]] for w in my_map]
    lst.sort(key=comp)
    tree_size = 1
    while (tree_size < size):
        tree_size <<= 1
    tree = [[0, 0, 0, '0' * (n // 2)] for i in range(2 * tree_size - 1 - size)] + lst
    for i in range(tree_size - 2, -1, -1):
        tree[i][0] = tree[2 * i + 1][0]
        tree[i][1] = tree[2 * i + 2][1]
        if tree[2 * i + 1][2] > tree[2 * i + 2][2]:
            tree[i][2], tree[i][3] = tree[2 * i + 1][2], tree[2 * i + 1][3]
        else:
            tree[i][2], tree[i][3] = tree[2 * i + 2][2], tree[2 * i + 2][3]
    return tree

def maxlook(element, l, r, tree):
    if tree[element][1] < l or tree[element][0] > r:
        return 0, '0' * (n // 2), False

    if tree[element][1] <= r and tree[element][1] >= l:
        return tree[element][2], tree[element][3], True

    price1, list1, flag1 = maxlook(2 * element + 1, l , r, tree)
    price2, list2, flag2 = maxlook(2 * element + 2, l , r, tree)
    if price1 > price2:
        return price1, list1, flag1 | flag2
    else:
        return price2, list2, flag1 | flag2

def generate(n):
    result = '0' * n
    cur_max_price = 0

    mid_meet_map = {0: [0, '0' * (n // 2)]}

    for i in range(1, 1 << n // 2):
        el = '0' * (n // 2 - i.bit_length()) + bin(i)[2:]
        weight = 0
        price = 0
        for k in range(n // 2):
            if el[k] == '1':
                weight += dowries[k][0]
                price += dowries[k][1]
        if weight <= max_w and ((weight in mid_meet_map and mid_meet_map[weight][0] < price) or weight not in mid_meet_map):
            mid_meet_map[weight] = [price, el]

    tree = treeBuild(mid_meet_map)

    for i in range(1, 1 << n - n // 2):
        el = '0' * (n - n // 2 - i.bit_length()) + bin(i)[2:]
        weight = 0
        price = 0
        for k in range(n - n // 2):
            if el[k] == '1':
                weight += dowries[n // 2 + k][0]
                price += dowries[n // 2 + k][1]
        if weight > max_w:
            continue
        pr, perm, found = maxlook(0, max(0, min_w - weight), max_w - weight, tree)
        if found and pr + price > cur_max_price:
            cur_max_price = pr + price
            result = perm + el

    return result

with open("dowry.in") as inf:
    n, min_w, max_w = map(int, inf.readline().split())
    dowries = []
    for i in range(n):
        dowries.append(list(map(int, inf.readline().split())))

result = generate(n)

with open("dowry.out", "w") as ouf:
    res = ''
    count = 0
    for i in range(n):
        if result[i] == '1':
            res += str(i + 1) + ' '
            count += 1
    ouf.write(str(count) + '\n' + res)
