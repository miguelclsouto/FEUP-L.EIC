
def search_tree(key, tree):
    
    return binary_search(key, tree)

def binary_search(key, tree):
    
    if tree == None:
        
        return tree
    
    if key == tree[0]:
        
        return (tree[1], [key])
    
    left = binary_search(key, tree[2])
    
    if left != None:
        
        return (left[0], [tree[0]] + left[1])
    
    right = binary_search(key, tree[3])
    
    if right != None:
        
        return (right[0], [tree[0]] + right[1])
    
    return None
    