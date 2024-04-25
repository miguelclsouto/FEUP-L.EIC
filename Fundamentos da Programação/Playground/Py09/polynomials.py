def evaluate(a, x):
    
    rng = list(range(len(a)))

    f = list(zip(a, rng))

    return sum(map(lambda y: y[0] * x**y[1], f))