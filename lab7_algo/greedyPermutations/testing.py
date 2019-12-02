import random

with open("dowry.in", "w") as ouf:
    res = ''
    for i in range(32):
        res += str(random.randint(1, 1000000000000000)) + ' ' \
               + str(random.randint(1, 1000000000000000)) + '\n'
    ouf.write('32 10000 10000000000000000\n' + res)