
def juggler(n, p):

    if p == 0:
        return n

    elif juggler(n, p-1) % 2 == 0:
        return int(juggler(n, p-1)**(1/2))

    return int(juggler(n, p-1)**(3/2))