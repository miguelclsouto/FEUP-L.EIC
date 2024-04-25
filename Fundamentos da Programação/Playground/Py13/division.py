def division(a, b):
    
    try:
        result = a / b
        
    except ZeroDivisionError:
        return "can't divide by 0!"
    
    except TypeError:
        return 'unsupported operand type(s) for division'
    
    else:
        return f'{a}/{b} = {result}'