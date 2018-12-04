# https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=666

from itertools import permutations


def division(n):
    digits = (str(a) for a in range(10))
    gen_ = permutations(digits, 5)
    is_find = False
    for x in gen_:
        x = int(''.join(x))
        y = x * n
        str_x, str_y = str(x), str(y)
        len_x, len_y = len(str_x), len(str_y)
        if len_y < 5:
            continue
        elif len_y > 5:
            break
        if len_x < 5:
            str_x = '0' + str_x
        if len(set(str_x) | set(str_y)) == 10:
            is_find = True
            print('{} / {} = {}'.format(str_y, str_x, n))
    if not is_find:
        print('There are no solutions for {}.'.format(n))
    return


if __name__ == '__main__':
    i = 0
    while True:
        n = int(input().strip())
        if n == 0:
            break
        if i != 0:
            print()
        i += 1
        division(n)