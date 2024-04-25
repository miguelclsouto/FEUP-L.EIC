def magic(mat):
    
    length = len(mat) # numero de lines
    colsum = [0] * length 
    linesum = [0] * length 
    diagsum1 = diagsum2 = 0
    
    for i in range(length): # len = 3
        for j in range(length):
            
            linesum[i] += mat[i][j] #[mat[i][j]]
            colsum[j] += mat[i][j] #[mat[i][j]]
            
            if i == j:
                
                diagsum1 += mat[i][j]
            if i == length - j - 1:
                
                diagsum2 += mat[i][j]
                
    
    for i in range(length - 1):
        
        if linesum[i] != linesum[i + 1] or colsum[i] != colsum[i + 1]:
            return False
        
    return diagsum1 == diagsum2

	


