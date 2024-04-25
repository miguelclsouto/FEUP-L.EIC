def mastermind(guesses, codes):
    
    points1 = 0
    points2 = 0
    newtuple = ()
    
    for i in range(len(guesses)):
        
        for j in range(len(codes)):
            
            if guesses[j] == codes[j]:
                
                points1 += 1
                
                codes[j] = 0
                
            elif guesses[i] == codes[j]:
                
                points2 += 1
                
                codes[j] = 0
                
                break
        
    if points1 != 0 or points2 != 0:
        
        newtuple += (points1, points2)
        
    return newtuple


