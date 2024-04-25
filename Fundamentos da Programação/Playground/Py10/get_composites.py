
def get_composites(n):
    
    l = list(filter(lambda x: not prime(x), range(4, n + 1)))
    
    return iter(l)

    # return (x for x in l)

def get_composites2(n):
    i = 4
    primes = {2, 3}
    l = []
    while i <= n:
        if prime(i):
            primes.add(i)
        else:
            yield i
            #l.append(i)
        i += 1

    #return (x for x in l)

def prime(n): # tb podia usar maps, reduces e filters para esta funcao

    for i in range(2, n // 2 + 1):

        if n % i == 0:
            return False

    return True