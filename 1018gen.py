with open('1.txt', 'w+') as f:
    f.write('100 498 498 664\n')
    for i in range(498):
        if i % 3 == 1: # 2 5 8 ...
            f.write('50 ')
        else:
            f.write('10 ')
    f.write('\n')
    for i in range(0, 498, 3):
        up = i + 1
        down = i + 2
        nxt = i + 3
        f.write('{} {} 1\n'.format(up, i))
        f.write('{} {} 1\n'.format(down, i))
        f.write('{} {} 1\n'.format(up, nxt))
        f.write('{} {} 1\n'.format(down, nxt))

