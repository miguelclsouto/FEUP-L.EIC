def evaluate(a, x):
    
    l = enumerate(a)
    
    l = [y[1]* x ** y[0] for y in l]

    return sum(l)