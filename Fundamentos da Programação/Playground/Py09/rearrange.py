def rearrange(l):

    f1 = list(filter(lambda x: x > 0, l))

    # o f2 e os que nao tao no f1
    f2 = list(filter(lambda x: x <= 0, l))

    return f2 + f1