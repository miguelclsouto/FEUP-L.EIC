# ou podias usar o metodo bin() para obteres 
# a string do numero em binario e depois
# verificavas se existia algum "11" na string

def no_consecutives1(k):
    return len(add(2**k - 1))

def verifier(k, check = False): # verifica se um num em base 10 tem ou nao 1s consecutivos em binario
    q = k // 2
    r = k % 2
    
    if r == 1:
        if check:
            return False
        check = True
    
    elif q == 0:
        return True
    
    else:
        check = False
    
    return verifier(q, check) 

def add(k):
    
    if k < 0:
        return []
    
    elif verifier(k):
        return [k] + add(k - 1)
    
    # caso o verifier seja Falso
    
    return add(k - 1)

# RECURSAO :)