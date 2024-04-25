
def differences(alist):
    return list(map(lambda x: x[0] - x[1], zip(alist[1:], alist)))

