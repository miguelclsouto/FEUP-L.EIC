def change2(amount):
    
    money = [200, 100, 50, 20, 10, 5, 2, 1]
    changemoney = []
    
    for i in money:
        while amount // i > 0:
            
            changemoney.append(i)
            amount -= i
            
    return changemoney

def change(amount):
    
    money = [200, 100, 50, 20, 10, 5, 2, 1]
    changemoney = []
    num = 0
    
    for i in money:
        
        num = amount // i
        
        changemoney += [i] * num
        
        amount %= i
        
    return changemoney
        