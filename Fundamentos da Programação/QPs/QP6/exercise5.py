def mult(M, N):
    
    #linematrix = []
    #colmatrix = []
    
    if len(N) != len(M[0]): # nao da para multiplicar estas matrizes
        return []
    
    newmatrix = [[0 for _ in range(len(N[0]))] for _ in range(len(M))]
    
    for i in range(len(M)): # numero de lines
        for j in range(len(N[0])): # numero de columns
            for k in range(len(M[0])): # ou len(N) # len das col
                
                newmatrix[i][j] += M[i][k] * N[k][j]
                
    return newmatrix            
            