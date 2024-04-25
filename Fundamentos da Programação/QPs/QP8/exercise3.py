def max_path(tree):
    
    if type(tree) is int:
        
        return tree
    
    middle = tree[1]
    
    left = max_path(tree[0])
    
    right = max_path(tree[2])
    
    return tree[1] + max(left, right)
    
    
    # max = 0
    # sum1, sum2, sum3 = 0
    # length = len(tree) 
    
    # if tree[0] is tuple:
    #     max_path(tree[0])
    
    # elif tree[1] is tuple:
    #     max_path(tree[1])
    
    # elif tree[2] is tuple:
    #     max_path(tree[2])
        
    # else:
    #     sum1 += tree[0] + tree[1]
    #     sum2 += tree[1] + tree[2]
    #     sum3 += tree[0] + tree[2]
    
    # max(sum1, sum2, sum3)
            