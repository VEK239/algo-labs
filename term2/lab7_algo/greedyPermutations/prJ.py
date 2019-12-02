def bit_count(st):
    return st.count('1')

def generate(n, pieces):
    result = '0' * n
    bitcount = 0

    mid_meet_map = {0: '0' * (n // 2)}

    for i in range((1 << n // 2) - 1, 0, -1):
        el = '0' * (n // 2 - i.bit_length()) + bin(i)[2:]
        res = 0
        for k in range(n // 2):
            if el[k] == '1':
                res ^= pieces[k]
        if (res in mid_meet_map and bit_count(mid_meet_map[res]) < bit_count(el)) or res not in mid_meet_map:
            mid_meet_map[res] = el

    for i in range(1 << (n - n // 2), 0, -1):
        el = '0' * (n - n // 2 - i.bit_length()) + bin(i)[2:]
        res = 0
        for k in range(n - n // 2):
            if el[k] == '1':
                res ^= pieces[n // 2 + k]
        if res in mid_meet_map and (bitcount < bit_count(el) + bit_count(mid_meet_map[res])):
            bitcount = bit_count(el) + bit_count(mid_meet_map[res])
            result = mid_meet_map[res] + el
    return result, bitcount

with open("jurassic.in") as inf:
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    n = int(inf.readline())
    pieces = []
    for i in range(n):
        res = 0
        st = inf.readline().split('\n')[0]
        for i in range(26):
            if alphabet[i] in st:
                res += pow(2, i)
        pieces.append(res)

result, count = generate(n, pieces)

with open("jurassic.out", "w") as ouf:
    res = ''
    for i in range(n):
        if result[i] == '1':
            res += str(i + 1) + ' '
    ouf.write(str(count) + '\n' + res)