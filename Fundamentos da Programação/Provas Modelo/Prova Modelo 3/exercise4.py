

def list_paths(dirtree):
    
    # eu basicamente faco return da lista sempre e 
    # faco prepend da root exatamente acima da subtree
    # em todas as posicoes da lista recursivamente
    
    # o importante aqui e perceber com esta organizada a arvore --> (string, list) -- non-leaf node -- / (string, string) -- leaf node -- e dentro da lista pode ter um tuplo ou
    
    final = []
    
    # if len(dirtree) < 2:
    #     return []

    top = dirtree[0]
    

    for path in dirtree[1]: # estou a ver o que esta dentro da lista
        
        
        if type(path) is tuple:
            
            paths = list_paths(path)
        
        
            # caso paths nao seja uma lista vazia, ent
            
            for item in paths: # queremos fzr append de cada um dos itens da lista
                final.append(top + '/' + item)
            
             
        
        else: # quer dizer que e uma file, ent quero adicionar a file a lista
            
            final.append(top + '/' + path) # queres so adicionar a file a lista
    
    return final


def aux(tree):
    pass
 
