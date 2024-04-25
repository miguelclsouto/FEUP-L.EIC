#n = int(input()) #possibilities

#r = int(input()) #number of selected objects

def fact(n):
    
    # ou n <= 1
    if n in [0, 1]:
        
        return 1
    
    return n * fact(n-1)

def C(n, r):

    return round(fact(n) / (fact(r) * fact(n - r)))



#print(round(comb(n,r)))