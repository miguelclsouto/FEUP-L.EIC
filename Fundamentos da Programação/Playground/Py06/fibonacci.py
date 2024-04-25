# conseguiria fzr isto tb usando variaveis globais para ter o fib de n - 1 e de n - 2, 
# teria entao que atualizar estas variaveis sempre que passava para n = n + 1 (n++)

def fib(n):
    return list(map(lambda x: fibonacci(x), range(n)))

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

def fib2(n):
    
    l = []
    
    for i in range(n):
        
        if i < 2:
            
            l += [i]
            continue
        
        l += [l[-2] + l[-1]]
        
    return l