def mastermind(g1, g2, g3, c1, c2, c3):
    points = 0
    
    # mudando as cenas para numeros, tenho a certeza de que nao havera repeticoes
    
    if g1 == c1:
        
        points += 3
        g1 = c1 = "0"
        
    if g2 == c2:
        
        points += 3
        g2 = c2 = "1" 
        
    if g3 == c3:
        
        points += 3 
        g3 = c3 = "2"

    if g1 == c2:
        
        points += 1
        c2 = "3"
        
    elif g1 == c3:
        
        points += 1
        c3 = "3"
    
    if g2 == c1:
        
        points += 1
        c1 = "4"
        
    elif g2 == c3:
        
        points += 1
        c3 = "4"
        
    if g3 == c1:
        
        points += 1
        c1 = "5"
        
    elif g3 == c2:
        
        points += 1
        c2 = "5"
        
    return points
          