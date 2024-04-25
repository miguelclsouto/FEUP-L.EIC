import random

def cows_bulls(seed_value):
    random.seed(seed_value)

    def inner(guess):
        
        num = random.randint(0, 9999)
        
        s = set(str(num)) # isto vai separar cada um dos digitos e vai criar um set com eles
        
        cows = 0
        
        bulls = 0
        
        num2 = num
        
        guess2 = guess
        
        # TENHO QUE VERIFICAR AS COWS PRIMEIRO
        
        for i in range(4):
            
            if num2 % 10 == guess2 % 10:
                cows += 1
                
            num2 //= 10
            guess2 //= 10
        
        num = str(num)
        
        guess = str(guess)
    
        while len(guess) != 4:
            guess = '0' + guess
            
        while len(num) != 4:
            num = '0' + num
        
        num = list(num)
        
        guess = list(guess)
        
        for i in range(4):
            
            if guess[i] in num:
                
                bulls += 1
                num.remove(guess[i])
        
        return (cows, bulls - cows)
    
    return inner