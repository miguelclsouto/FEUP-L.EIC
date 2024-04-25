        
def above(tree, name):
    
    l = []
    
    # queremos que isto seja tudo tuples
    
    # na recursao em arvores e importante perceber como 
    # esta organizada esta estrutura de dados
    
    # neste caso temos temos tuplos (string, list[tuple]) -- non-leaf nodes / (string, list[string]) -- leaf nodes 
    # e dentro das listas voltamos a ter um tuplo deste genero ( (string, list[tuple]) ou (string, list[string])).
    
    if type(tree) is str:
        
        if tree == name:
            return []
        
        return None
    
    if type(tree) is tuple and tree[0] == name:
        return []
    
    #if type(tree) is not str:
        
    for i in range(len(tree[1])):
            
        sub = tree[1][i] # tuples
            
        subtree = above(sub, name)
            
            
        if subtree != None:
            
            l.append(tree[0])
            
            return l + subtree
