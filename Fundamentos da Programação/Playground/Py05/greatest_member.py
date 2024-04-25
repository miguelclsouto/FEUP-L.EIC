from functools import reduce

def calculate_points(s):

    sum = 0

    for elem in s:

        if type(elem) is tuple:

            sum += calculate_points(elem)
        
        else: # is string / char
            
            sum += reduce(lambda x, y: x + y, map(lambda x : ord(x), elem))

    return sum

def calculate_points2(s):

    sum = 0

    if type(s) is str:

        for char in s:
            sum += ord(char)

    else: # type is tuple
        
        for elem in s:

            if type(elem) is tuple:

                sum += calculate_points2(elem)
            
            else: # is string / char
                
                sum += reduce(lambda x, y: x + y, map(lambda x : ord(x), elem))

    return sum

def greatest_member(a_tuple):
    
    greatest = a_tuple[0]  

    for t in a_tuple:

        if calculate_points(t) > calculate_points(greatest):
            greatest = t

    return greatest
