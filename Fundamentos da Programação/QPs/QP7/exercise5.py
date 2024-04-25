def next_middle_square(number, digits):
    
   """Compute the next pseudo-random using the 
      middle square algorithm and the given number of digits."""
      
   k = digits // 2         # half of the number of digits
   
   square = number*number  # compute the square
   
   middle = (square // (10**k)) % (10**digits)   # extract middle part
   
   return middle


def cycle_length(number, digits):
    l = {}
    i = 1
    
    while number not in l:
        
        l[number] = i
        number = next_middle_square(number, digits)
        
        i += 1
          
    return i - l[number]