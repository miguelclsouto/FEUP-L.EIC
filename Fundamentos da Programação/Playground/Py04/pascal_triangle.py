from math import factorial as fact

#num = int(input())
#n = 3

def pascal(n):
    
    finalsequence = ""
    
    for i in range(n):
        for j in range(i + 1):
            
            comb = fact(i) / (fact(j) * fact(i-j))
        
            if j == i:
                
                finalsequence = finalsequence + str(int(comb)) + "\n"
                
            else:
                
                finalsequence = finalsequence + str(int(comb)) + " "
        
    return finalsequence
    
     
#pascal(n)