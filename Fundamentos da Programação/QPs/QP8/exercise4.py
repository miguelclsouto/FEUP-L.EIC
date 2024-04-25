
def insert_char(char, string):
    
    # Generate all possible insertions of 'char' into 'string'.
    
    result = []
    
    for i in range(len(string) + 1):
        
        result.append(string[:i] + char + string[i:])
        
    return result

def permutations(str):
    
    if len(str) <= 1:
        
        # Base case: if the string is empty or has a single character, return itself.
        
        return [str]
    
    else:
        
        first_char = str[0]
        rest_of_str = str[1:]
        
        # Recursively compute the permutations of the tail of the string.
        
        rest_permutations = permutations(rest_of_str)
        result = []
        
        for perm in rest_permutations:
            
            # Insert the first character into each permutation of the rest of the string.
            
            result.extend(insert_char(first_char, perm))
            
        return result
        