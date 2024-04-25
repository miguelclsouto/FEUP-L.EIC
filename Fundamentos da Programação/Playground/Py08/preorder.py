
def preorder(tree):
    l = [tree[0]]
    
    if type(tree[1]) is tuple:
        l.extend(preorder(tree[1]))
    if type(tree[2]) is tuple:
        l.extend(preorder(tree[2]))
        
    return l

def preorder2(tree):

    if tree == None:
        return []
    
    return [tree[0]] + preorder(tree[1]) + preorder(tree[2])