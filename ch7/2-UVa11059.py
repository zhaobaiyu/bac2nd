from itertools import product
def any_product(l, a, b):
    ans = 1
    for v in l[a:b+1]:
        ans *= v
    return ans


def max_product(i_ord, l):
    ans = -1
    len_l = len(l)
    for i in range(len_l):
        for j in range(i, len_l):
            tmp = any_product(l, i, j)
            if tmp > ans:
                ans = tmp
    if ans == -1:
        ans = 0
    print('Case #{}: The maximum product is {}.'.format(i_ord, ans))
    return


if __name__ == '__main__':
    i = 1
    while True:
        try:
            n_str = input().strip()
            if n_str == '':
                continue
            l = [int(a) for a in input().strip().split()]
            max_product(i, l)
            print()
            i += 1
        except:
            break