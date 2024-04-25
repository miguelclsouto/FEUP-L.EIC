num = 2039


# podia tb calcular todos os numeros primos qe compoem o numero
# e depois verificava se eram o 5, 3 e 2 usando comapracao entre listas

def ugly(n):
    
    a = [5,3,2]
    
    for i in range(3):
        
        while n % a[i] == 0: # isto quer dizer que e um numero inteiro
            
            n //= a[i]
            
    if n == 1:
        
        return True
    
    return False

print(ugly(num))