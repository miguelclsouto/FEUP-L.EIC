from functools import reduce


def dec2int(alist):
    
    
    seq1 = list(range(len(alist)))[::-1]
    
    # ou faco seq1.reverse() 
    # [3, 2, 1, 0]
    
    # vou querer retornar 10**x (elevado a x)
    
    
    p = list(map(lambda x: 10**x, seq1)) # [1000, 100, 10, 1]
    
    
    # agora vais querer multiplicar as duas listas. Podes fazer um zip para isso
    
    
    k = list(zip(p, alist))
    
    
    # agora vais querer multiplicar ambos os valores do tuple
    
    #return sum(map(lambda x: x[0] * x[1], k))
    
    # ou usaando um reduce, ja que a funcao sum() e so um reduce aplicado a soma em especifico
    
    
    
    return reduce(lambda x, y: x + y, list(map(lambda x: x[0] * x[1], k)))


    