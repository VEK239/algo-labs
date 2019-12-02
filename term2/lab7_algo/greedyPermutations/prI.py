def multiply(matrix):
    res = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
    for i in range(4):
        for j in range(4):
            for k in range(4):
                res[i][j] += matrix[i][k] * matrix[k][j]
            res[i][j] = res[i][j] % 2
    return res


with open("sqroot.in") as inf:
    exists = False
    data = []
    for i in range(4):
        data.append(list(map(int, inf.readline().split())))
    changes = [['0', '0', '0', '0']]
    for i in range(1, 16):
        changes.append(list('0' * (4 - i.bit_length()) + bin(i)[2:]))
    for i in range(len(changes)):
        for j in range(4):
            changes[i][j] = int(changes[i][j])
    ok = True
    for first in changes:
        for second in changes:
            for third in changes:
                for fourth in changes:
                    res = multiply([first, second, third, fourth])
                    correct = True
                    for i in range(4):
                        for j in range(4):
                            if res[i][j] != data[i][j]:
                                correct = False
                                break
                        if not correct:
                            break
                    if correct:
                        matrix = [first, second, third, fourth]
                        exists = True
                        break
                if exists:
                    break
            if exists:
                break
        if exists:
            break

    with open("sqroot.out", "w") as ouf:
        if exists:
            st = ''
            for i in range(4):
                for j in range(4):
                    st += str(matrix[i][j]) + ' '
                st += '\n'
            ouf.write(st)
        else:
            ouf.write("NO SOLUTION")
